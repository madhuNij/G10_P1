#include <iostream>
#include <memory>
#include <string>
#include <sys/stat.h>
#include <grpc++/grpc++.h>

#include "wiscAFS.grpc.pb.h"

using namespace std;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientWriter;
using grpc::Status;
using wiscAFS::GetAttrReply;
using wiscAFS::GetAttrReq;
using wiscAFS::OpenReply;
using wiscAFS::OpenReq;
using wiscAFS::WiscAFS;
using wiscAFS::HelloRequest;
using wiscAFS::HelloReply;
using wiscAFS::MkDirReply;
using wiscAFS::MkDirReq;
using wiscAFS::ReadReply;
using wiscAFS::ReadReq;
using wiscAFS::WriteReq;
using wiscAFS::WriteReply;
using wiscAFS::ReadDirReq;
using wiscAFS::ReadDirReply;
using wiscAFS::RmDirReply;
using wiscAFS::RmDirReq;
using wiscAFS::WriteReply;
using wiscAFS::WriteReq;

#define BLOCK_SIZE 1048576 // 1Mb

class WiscAFSClient
{
public:
    WiscAFSClient(shared_ptr<Channel> channel) : stub_(WiscAFS::NewStub(channel)){
    }

    int GetAttr(string &path, string &buf)
    {
        GetAttrReq request;
        request.set_path(path);
        GetAttrReply reply;
        ClientContext context;
        Status status = stub_->GetAttr(&context, request, &reply);
        if (status.ok())
        {
            buf = reply.buf();

            // print buf details using stat structure
            struct stat sb;
            memcpy(&sb, &buf[0],buf.size());
            cout <<"File type:                ";

            switch (sb.st_mode & S_IFMT)
            {
            case S_IFBLK:
                cout << "block device\n";
                break;
            case S_IFCHR:
                cout << "character device\n";
                break;
            case S_IFDIR:
                cout << "directory\n";
                break;
            case S_IFIFO:
                cout << "FIFO/pipe\n";
                break;
            case S_IFLNK:
                cout << "symlink\n";
                break;
            case S_IFREG:
                cout << "regular file\n";
                break;
            case S_IFSOCK:
                cout << "socket\n";
                break;
            default:
                cout << "unknown?\n";
                break;
            }

            cout << "I-node number:            " << (long)sb.st_ino << endl;
            cout << "Mode:                      (octal) " << (unsigned long)sb.st_mode << endl;
            cout << "Link count:               "<< (long)sb.st_nlink<<endl;
            cout << "Ownership:                UID= " << (long)sb.st_uid << "GID= " << (long)sb.st_gid << endl;
            cout << "Preferred I/O block size: bytes" << (long)sb.st_blksize << endl;
            cout << "File size:                bytes" << (long long)sb.st_size << endl;
            cout << "Blocks allocated:         %lld" << (long long)sb.st_blocks << endl;
            cout << "Last status change:       " << ctime(&sb.st_ctime) << endl;
            cout << "Last file access:         " << ctime(&sb.st_atime) << endl;
            cout << "Last file modification:   " << ctime(&sb.st_mtime) << endl;

            return reply.err();
        }
        else
        {
            return -1;
        }
    }

    int Open(string &path, int flag){
        OpenReq request;
        request.set_path(path);
        request.set_flag(flag);
        OpenReply reply;
        ClientContext context;
        Status status = stub_->Open(&context, request, &reply);

        return status.ok() ? reply.err() : -1;
    }

    int Read(string &path, string& buf, int size, int offset){
        ReadReq request;
        request.set_path(path);
        request.set_size(size);
        request.set_offset(offset);
        ReadReply reply;
        ClientContext context;
        unique_ptr<ClientReader<ReadReply>>reader(stub_->Read(&context, request));
        
        buf = string();
        buf.reserve(size);
        while (reader->Read(&reply)) {
            buf += reply.buf();
            if (reply.num_bytes() < 0) {
                break;
            }
        }
        Status status = reader->Finish();
        return status.ok() ? buf.size() : -1;
    }

    int Write(string &path, string& data, int size, int offset){
        WriteReq request;
        WriteReply reply;
        ClientContext context;
        unique_ptr<ClientWriter<WriteReq>>writer(stub_->Write(&context, &reply));
        int bytesWritten = size;
        int curr = offset;
        while(bytesWritten>=0){
            request.set_path(path); 
            request.set_buf(data.substr(curr, std::min(BLOCK_SIZE, bytesWritten)));
            request.set_size(std::min(BLOCK_SIZE, bytesWritten));
            request.set_offset(curr);
            curr += BLOCK_SIZE;
            bytesWritten -= BLOCK_SIZE;
            if (!writer->Write(request)) {
                // Broken stream.
                break;
            }
        }
        writer->WritesDone();
        Status status = writer->Finish();

        return status.ok() ? reply.num_bytes() : -1;

    }

    int ReadDir(string& path, vector<string>& buf) {
        ReadDirReq request;
        request.set_path(path);

        ReadDirReply reply;
        ClientContext context;

        unique_ptr<ClientReader<ReadDirReply> > reader(stub_->ReadDir(&context, request));

        while (reader->Read(&reply)) {
            buf.push_back(reply.buf());
            if (reply.err() < 0) {
                break;
            }
        }

        Status status = reader->Finish();

        return status.ok() ? reply.err() : -1;
    }

    int MkDir(const string& path, int mode) {
        MkDirReq request;
        request.set_path(path);
        request.set_mode(mode);

        MkDirReply reply;
        ClientContext context;
        Status status = stub_->MkDir(&context, request, &reply);

        return status.ok() ? reply.err() : -1;
    }

    int RmDir(const std::string& path) {
        RmDirReq request;
        request.set_path(path);

        RmDirReply reply;
        ClientContext context;
        Status status = stub_->RmDir(&context, request, &reply);

        return status.ok() ? reply.err() : -1;
    }
    //============================Testing=============
    string SayHello(const std::string &user)
    {
        // Data we are sending to the server.
        HelloRequest request;
        request.set_name(user);
        HelloReply reply;
        ClientContext context;
        Status status = stub_->SayHello(&context, request, &reply);

        if (status.ok())
        {
            return reply.message();
        }
        else
        {
            return "RPC failed";
        }
    }

private:
    std::unique_ptr<WiscAFS::Stub> stub_;
};

