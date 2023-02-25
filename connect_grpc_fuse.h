#include <dirent.h>
#include <errno.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fuse.h>

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
int connect_grpc_fuse_initialize();
int connect_grpc_fuse_getattr(const char *path, struct stat *buf);
int connect_grpc_fuse_open(const char *path, struct fuse_file_info *fi);
int connect_grpc_fuse_read(const char *path, char *buf, size_t size, off_t offset,
                    struct fuse_file_info *fi);
int connect_grpc_fuse_write(const char *path, const char *buf, size_t size,
                     off_t offset, struct fuse_file_info *fi);
int connect_grpc_fuse_mkdir(const char *path, mode_t mode);
int connect_grpc_fuse_rmdir(const char *path);
int connect_grpc_fuse_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
                       off_t offset, struct fuse_file_info *fi);
int connect_grpc_fuse_create(const char *path, mode_t mode,
                      struct fuse_file_info *fi);
int connect_grpc_fuse_lstat(const char* path, struct stat* buf);
int connect_grpc_fuse_readlink(const char* path, char* buf, size_t bufsiz);
int connect_grpc_fuse_mknod(const char* path, mode_t mode, dev_t dev);
int connect_grpc_fuse_unlink(const char* path);
int connect_grpc_fuse_symlink(const char* target, const char* linkpath);
int connect_grpc_fuse_rename(const char* oldpath, const char* newpath);
int connect_grpc_fuse_link(const char* oldpath, const char* newpath);
int connect_grpc_fuse_chmod(const char* path, mode_t mode);
int connect_grpc_fuse_chown(const char* path, uid_t owner, gid_t group);
// 9. truncate(self, path, size)
int connect_grpc_fuse_truncate(const char* path, off_t length);
int connect_grpc_fuse_statfs(const char* path, struct statvfs* buf);
int connect_grpc_fuse_flush(const char* path, struct fuse_file_info* fi);
// 7. release(self, path, flags)
int connect_grpc_fuse_release(const char* path, struct fuse_file_info* fi);
// 14. fsync(self, path, isfsyncfile
int connect_grpc_fuse_fsync(const char* path, int datasync, struct fuse_file_info* fi);
int connect_grpc_fuse_setxattr(const char* path, const char* name, const char* value, size_t size, int flags);
int connect_grpc_fuse_getxattr(const char* path, const char* name, char* value, size_t size);
int connect_grpc_fuse_listxattr(const char* path, char* list, size_t size);
int connect_grpc_fuse_removexattr(const char* path, const char* name);
int connect_grpc_fuse_opendir(const char* path, struct fuse_file_info* fi);
int connect_grpc_fuse_releasedir(const char* path, struct fuse_file_info* fi);
int connect_grpc_fuse_fsyncdir(const char* path, int datasync, struct fuse_file_info* fi);
int connect_grpc_fuse_access(const char* path, int mode);
int connect_grpc_fuse_ftruncate(const char* path, off_t length, struct fuse_file_info* fi);
int connect_grpc_fuse_fgetattr(const char* path, struct stat* buf, struct fuse_file_info* fi);
int connect_grpc_fuse_lock(const char* path, struct fuse_file_info* fi, int cmd, struct flock* fl);
int connect_grpc_fuse_ioctl(const char* path, int cmd, void* arg, struct fuse_file_info* fi, unsigned int flags, void* data);
int connect_grpc_fuse_flock(const char* path, struct fuse_file_info* fi, int op);
int connect_grpc_fuse_fallocate(const char* path, int mode, off_t offset, off_t len, struct fuse_file_info* fi);
int connect_grpc_fuse_utimens(const char* path, const struct timespec ts[2]);
#ifdef __cplusplus
}

#endif
