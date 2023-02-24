#include <iostream>
#include <cassert>
#include <memory>
#include <string>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>

#include <grpc++/grpc++.h>

#include "wiscAFS.grpc.pb.h"

using namespace std;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::ServerReader;
using grpc::Status;
using wiscAFS::GetAttrReq;
using wiscAFS::GetAttrReply;
using wiscAFS::OpenReq;
using wiscAFS::OpenReply;;
using wiscAFS::ReadReq;
using wiscAFS::ReadReply;
using wiscAFS::WriteReq;
using wiscAFS::WriteReply;
using wiscAFS::ReadDirReq;
using wiscAFS::ReadDirReply;
using wiscAFS::MkDirReq;
using wiscAFS::MkDirReply;
using wiscAFS::RmDirReq;
using wiscAFS::RmDirReply;
using wiscAFS::UnlinkReq;
using wiscAFS::UnlinkReply;
using wiscAFS::HelloRequest;
using wiscAFS::HelloReply;
using wiscAFS::WiscAFS;

#define BLOCK_SIZE 4096 // 1Mb

class WiscAFSImpl final : public WiscAFS::Service {
    public:
        const string root_path;
        //default constructor
        WiscAFSImpl(): root_path(""){}

        Status GetAttr(ServerContext* context, const GetAttrReq* request, GetAttrReply* response) {
            
            string path = root_path + request->path();
            printf("\nGetAttr: %s \n", path.c_str());
            response->set_status(0);
            int res;
            struct stat stbuf;
            res = lstat(path.c_str(), &stbuf);
            if ( res != -1){
                string buf;
                int stat_size = sizeof(struct stat);
                buf.resize(stat_size);
            //cout << "Buffer in getattr" << buf << endl;
                memcpy(&buf[0], &stbuf, buf.size());
                response->set_buf(buf);
                response->set_status(0); 
                response->set_modified_time(stbuf.st_mtime);
            }    
            else{
                response->set_err(errno);
                response->set_status(-1);
            }
            cout<<"\n status: "<<response->status()<<"\n error: "<< errno;
	        
                return Status::OK;
        }

        
        Status Open(ServerContext* context, const OpenReq* request, OpenReply* response) override{
        
            response->set_err(0);

            string path = root_path + request->path();
            printf("Open: %s \n", path.c_str());

            int res;

            res = open(path.c_str(), (mode_t)request->flag(),S_IRWXG | S_IRWXO | S_IRWXU); 
            if (res == -1) {
                response->set_err(-errno);
                return Status::OK;
            }
            close(res);
            response->set_err(0);
            return Status::OK;
        }

        Status Read(ServerContext* context, const ReadReq* request,ServerWriter<ReadReply>* writer) override {
            ReadReply* reply = new ReadReply();
            reply->set_num_bytes(0);
            int res;
            string path = root_path + request->path();
            printf("Read stream path: %s \n", path.c_str());
            int size = request->size();
            int offset = request->offset();

            int fd = open(path.c_str(), O_RDONLY);
            if (fd == -1) {
                reply->set_num_bytes(-1);
                return Status::OK;
            }

            string buf;
            buf.resize(size);
            cout << "Request size" <<size;
            
            int bytesRead = pread(fd, &buf[0], size, offset);
            cout << "Bytes read:" <<bytesRead;
            if (bytesRead != size) {
                printf("Read: PREAD didn't read %d bytes from offset %d\n", size, offset);
            } 
            if (bytesRead == -1) {
                reply->set_num_bytes(-errno);
            }

            int remainBytes = bytesRead;
            int curr = 0;
            
            while (remainBytes > 0) {
                reply->set_buf(buf.substr(curr, std::min(BLOCK_SIZE, remainBytes)));
                reply->set_num_bytes(std::min(BLOCK_SIZE, remainBytes));
                curr += BLOCK_SIZE;
                remainBytes -= BLOCK_SIZE;
                writer->Write(*reply);
            }
            if(fd > 0)
                close(fd);
            return Status::OK;
        }

        Status Write(ServerContext* context, ServerReader<WriteReq>* reader, WriteReply* response) override{
            WriteReq request;
            int fd, res, size, offset, num_bytes = 0;
            response->set_num_bytes(num_bytes);
            while (reader->Read(&request)) {
                string path = root_path + request.path();
                size = request.size();
                offset = request.offset();
                string buf = request.buf();
                if(num_bytes==0){
                    fd = open(path.c_str(), O_CREAT | O_SYNC | O_WRONLY, S_IRWXG | S_IRWXO | S_IRWXU);
                    if (fd == -1) {
                        response->set_num_bytes(-errno);
                        return Status::OK;
                    }
                    printf("Write stream path: %s \n", path.c_str());
                }
                res = pwrite(fd, &buf[0], size, offset);
                // pwrite returns -1 when error, and store type in errno
                if (res == -1) {
                    response->set_num_bytes(-errno);
                    return Status::OK;
                }
                num_bytes += res;
            }
            if (fd > 0) {
                fsync(fd);
                close(fd);
            }
            response->set_num_bytes(num_bytes);
            
            return Status::OK;
        }

        Status ReadDir(ServerContext* context, const ReadDirReq* request, ServerWriter<ReadDirReply>* writer) override{
            ReadDirReply *reply = new ReadDirReply();
            string path = root_path + request->path();
            printf("ReadDir: %s \n", path.c_str());

            DIR *dp;
            struct dirent *de;

            dp = opendir(path.c_str());
            if (dp == NULL) {
                reply->set_err(-errno);
                return Status::OK;
            }
            std::vector<std::string> dirs;
            while ((de = readdir(dp)) != NULL) {
                std::string buf;
                buf.resize(sizeof(struct dirent));
                memcpy(&buf[0], de, buf.size());
                dirs.push_back(buf);
            }
            closedir(dp);
            for (auto dir: dirs){
                reply->set_buf(dir);
                writer->Write(*reply);
            }
            return Status::OK;
        }    

        Status MkDir(ServerContext* context, const MkDirReq* request, MkDirReply* response) override {
            string path = root_path + request->path();
            response->set_err(0);
            printf("MkDir at path: %s \n", path.c_str());
            int res;
            res = mkdir(path.c_str(), (mode_t)request->mode());
            if ( res!= 0){
                printf("error");
		        response->set_err(-errno);
                return Status::OK;
            }
	    printf("success");
            response->set_err(0);
            return Status::OK;
    
        }

        Status RmDir(ServerContext* context, const RmDirReq* request, RmDirReply* response) {
            string path = root_path + request->path();
            response->set_err(0);
            printf("RmDir at path: %s \n", path.c_str());
            int res;
            res = rmdir(path.c_str());
            if ( res < 0){
                response->set_err(-errno);
                return Status::OK;
            }
            response->set_err(res);
            return Status::OK;
    
        }

        Status Unlink(ServerContext* context, const UnlinkReq* request,
                UnlinkReply* reply) override {
            // default errno = 0
            reply->set_status(0);
            std::string path = root_path + request->path();
            printf("Unlink: %s \n", path.c_str());
            int res;
            res = unlink(path.c_str());
            if (res == -1) {
                reply->set_status(-errno);
                return Status::OK;
            }
            reply->set_status(res);
            return Status::OK;
        }

//========================================= Test Function =====================================
        Status SayHello(ServerContext* context, const HelloRequest* request, HelloReply* reply) override {
            std::string prefix("Hello ");
            reply->set_message(prefix + request->name());
            return Status::OK;
        }    
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    WiscAFSImpl service;

    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}
