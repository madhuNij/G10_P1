#include <grpc++/grpc++.h>
#include "./connect_grpc_fuse.h"
#include "wiscAFS_client.h"
#include<fuse.h>
#ifdef __cplusplus
extern "C" {
#endif

// all of your legacy C code here
//GetAttr
int connect_grpc_fuse_getattr(const char *path, struct stat *buf)
{
    string hostport;
    std::cout << "connect GRPC FUSE getattr" << std::endl;
    hostport = "128.105.144.70:50051";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    std::memset(buf, 0, sizeof(struct stat));
    int ret = client.GetAttr(_path, buf);
    if (ret == -1) {
        return -errno;
    }

    return 0;
}

//Open
int connect_grpc_fuse_open(const char *path, struct fuse_file_info *fi)
{
    string hostport;
    std::cout << "connect GRPC FUSE open" << std::endl;
    hostport = "128.105.144.70:50051";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    int ret;
    const std::string _path(path);
    ret = client.Open(_path, fi->flags);
    //ret = open(path, fi->flags);
    if (ret == -1) {
        return -errno;
    }
    fi->fh = ret;

    return 0;
}
//Read
int connect_grpc_fuse_read(const char *path, char *buf, size_t size, off_t offset,
                    struct fuse_file_info *fi)
{
    string hostport;
    std::cout << "connect GRPC FUSE read" << std::endl;
    hostport = "128.105.144.70:50051";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    std::string _buf(buf);
    int ret = client.Read(_path, _buf, (int)size, (int)offset);
    //ret = pread(fd, buf, size, offset);
    if (ret == -1) {
        ret = -errno;
    }

    return ret;
}
//Write
int connect_grpc_fuse_write(const char *path, const char *buf, size_t size,
                     off_t offset, struct fuse_file_info *fi)
{
    string hostport;
    std::cout << "connect GRPC FUSE write" << std::endl;
    hostport = "128.105.144.70:50051";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    std::string _buf(buf);
    int ret = client.Write(_path, _buf, (int)size, (int)offset);
    //ret = pwrite(fd, buf, size, offset);
    if (ret == -1) {
        ret = -errno;
    }

    return ret;
}
//ReadDir
//MkDir
int connect_grpc_fuse_mkdir(const char *path, mode_t mode)
{
    string hostport;
    std::cout << "connect GRPC FUSE mkdir" << std::endl;
    hostport = "128.105.144.70:50051";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    int ret;
    ret = client.MkDir(_path, mode);
    ret = mkdir(path, mode);
    if (ret == -1) {
        return -errno;
    }

    return 0;
}
//RmDir
int connect_grpc_fuse_rmdir(const char *path)
{
    string hostport;
    std::cout << "connect GRPC FUSE rmdir" << std::endl;
    hostport = "128.105.144.70:50051";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    int ret;
    ret = client.RmDir(_path);
    //ret = rmdir(path); 
    if (ret == -1) {
        return -errno;
    }
    return 0;
}
#ifdef __cplusplus
}
#endif
/*int main(){
    return 0;
}*/
