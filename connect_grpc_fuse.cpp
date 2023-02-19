#include "./connect_grpc_fuse.h"
#ifdef __cplusplus
extern "C" {
#endif

// all of your legacy C code here
//GetAttr
int connect_grpc_fuse_getattr(const char *path, struct stat *buf)
{
    string hostport;
    std::cout << "connect GRPC FUSE getattr" << std::endl;
    hostport = "localhost:50051";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    std::memset(buf, 0, sizeof(struct stat));
    int ret = client.GetAttr(_path, buf);
    if (ret == -1) {
        return -errno;
    }

    return 0;
}
/*
//Open
int connect_grpc_fuse_open(const char *path, struct fuse_file_info *fi)
{
    ret = open(path, fi->flags);
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
    int fd;

    if (fi == NULL) {
	fd = open(path, O_RDONLY);
    } else {
	fd = fi->fh;
    }

    if (fd == -1) {
	return -errno;
    }

    ret = pread(fd, buf, size, offset);
    if (ret == -1) {
        ret = -errno;
    }
    if (fi == NULL) {
	close(fd);
    }

    return ret;
}
//Write
int connect_grpc_fuse_write(const char *path, const char *buf, size_t size,
                     off_t offset, struct fuse_file_info *fi)
{
    int fd;
    (void) fi;
    if(fi == NULL) {
	fd = open(path, O_WRONLY);
    } else {
	fd = fi->fh;
    }

    if (fd == -1) {
	return -errno;
    }

    ret = pwrite(fd, buf, size, offset);
    if (ret == -1) {
        ret = -errno;
    }

    if(fi == NULL) {
        close(fd);
    }

    return ret;
}
//ReadDir
//MkDir
int connect_grpc_fuse_mkdir(const char *path, mode_t mode)
{
    ret = mkdir(path, mode);
    if (ret == -1) {
        return -errno;
    }

    return 0;
}
//RmDir
int connect_grpc_fuse_rmdir(const char *path)
{
    ret = rmdir(path); 
    if (ret == -1) {
        return -errno;
    }

    return 0;
}*/
#ifdef __cplusplus
}
#endif
