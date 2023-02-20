#include <iostream>
#include <memory>
#include <string>
#include <sys/stat.h>
#include <grpc++/grpc++.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
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
    WiscAFSClient(std::shared_ptr<Channel> channel);
    int GetAttr(const std::string &path, struct stat*);
    int Open(string &path, int flag);
    int Read(string &path, string& buf, int size, int offset);
    int Write(string &path, string& data, int size, int offset);
    int ReadDir(string& path, vector<string>& buf);
    int MkDir(const string& path, int mode);
    int RmDir(const std::string& path);
    string SayHello(const std::string &user);

private:
    std::unique_ptr<WiscAFS::Stub> stub_;
};

