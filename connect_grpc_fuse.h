#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/ioctl.h>
#include <sys/file.h>
#ifdef HAVE_XATTR
#include <sys/xattr.h>
#endif /* HAVE_XATTR */

#ifdef linux
/* For pread()/pwrite()/utimensat() */
#define _XOPEN_SOURCE 700
#endif

#define ERRNO_NOOP -999
#ifdef __cplusplus
extern "C" {
#endif

// all of your legacy C code here

int connect_grpc_fuse_getattr(const char *path, struct stat *buf);
/*int connect_grpc_fuse_open(const char *path, struct fuse_file_info *fi);
int connect_grpc_fuse_read(const char *path, char *buf, size_t size, off_t offset,
                    struct fuse_file_info *fi);
int connect_grpc_fuse_write(const char *path, const char *buf, size_t size,
                     off_t offset, struct fuse_file_info *fi);
int connect_grpc_fuse_mkdir(const char *path, mode_t mode);
int connect_grpc_fuse_rmdir(const char *path);*/
#ifdef __cplusplus
}

#endif
