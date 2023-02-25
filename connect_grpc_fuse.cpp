#include <grpc++/grpc++.h>
#include "./connect_grpc_fuse.h"
#include "wiscAFS_client.h"
#include <fuse.h>
#include <fstream>
#include "CacheUtil.cpp"
#ifdef __cplusplus
extern "C"
{
#endif

  string hostport = "128.105.144.70:50051";

  // all of your legacy C code here
  // GetAttr

  int connect_grpc_fuse_initialize()
  {
    cout << "\n--- Initialize ---\n";
    createCacheDirectory();
    // client = grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials());
    return 0;
  }

  int connect_grpc_fuse_getattr(const char *path, struct stat *buf)
  {
    int errornum;
    std::cout << "\n--- connect GRPC FUSE getattr ---\n";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    std::memset(buf, 0, sizeof(struct stat));
    int ret = client.GetAttr(_path, buf, errornum);
    if (ret == -1)
    {
      return -errornum;
    }

    return 0;
  }

  // lstat
  int connect_grpc_fuse_lstat(const char *path, struct stat *buf)
  {
    std::cout << "\n--- connect_grpc_fuse_lstat ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();

    memset(buf, 0, sizeof(struct stat));
    if (lstat(path, buf) == -1)
      return -errno;

    return 0;
  }

  // readlink
  int connect_grpc_fuse_readlink(const char *path, char *buf, size_t bufsiz)
  {
    std::cout << "\n--- connect_grpc_fuse_readlink ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret = readlink(path, buf, bufsiz);
    if (ret == -1)
    {
      return -errno;
    }
    buf[ret] = 0;

    return 0;
  }

  // mknod
  int connect_grpc_fuse_mknod(const char *path, mode_t mode, dev_t dev)
  {
    std::cout << "\n--- connect_grpc_fuse_mknod ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret = mknod(path, mode, dev);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  // unlink
  int connect_grpc_fuse_unlink(const char *path)
  {
    std::cout << "\n--- connect_grpc_fuse_unlink ---\n";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    int ret;
    ret = client.Unlink(path);
    if (ret == -1)
    {
      return -errno;
    }
    return 0;
  }

  // symlink
  int connect_grpc_fuse_symlink(const char *target, const char *linkpath)
  {
    std::cout << "\n--- connect_grpc_fuse_symlink ---\n";

    int ret = symlink(target, linkpath);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_rename(const char *oldpath, const char *newpath)
  {
    std::cout << "\n--- connect_grpc_fuse_rename ---\n";

    int ret = rename(oldpath, newpath);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_link(const char *oldpath, const char *newpath)
  {
    std::cout << "\n--- connect_grpc_fuse_link ---\n";

    int ret = link(oldpath, newpath);
    if (ret < 0)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_chmod(const char *path, mode_t mode)
  {
    std::cout << "\n--- connect_grpc_fuse_chmod ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret = chmod(path, mode);
    if (ret < 0)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_chown(const char *path, uid_t owner, gid_t group)
  {
    std::cout << "\n--- connect_grpc_fuse_chown ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();    
    int ret = chown(path, owner, group);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_truncate(const char *path, off_t length)
  {
    std::cout << "\n--- connect_grpc_fuse_truncate ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret = truncate(path, length);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  // Open
  int connect_grpc_fuse_open(const char *path, struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect GRPC FUSE open ---\n";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    int ret, attrRet, errornum;
    ;
    const std::string _path(path);
    string cachePath = getCacheFilePath(_path);

    struct stat localAttr, serverAttr;
    bool isValidCache = true;

    int lstatValue = lstat(cachePath.c_str(), &localAttr);
    attrRet = client.GetAttr(_path, &serverAttr, errornum);
    int serverTime = serverAttr.st_mtime;
    int cacheTime = localAttr.st_mtime;
    if (serverTime > cacheTime) {
      isValidCache = false; 
    }
    if (isValidCache) {
      cout << "\nOpening cache file\n";
      string cachePath = getCacheFilePath(_path);
      ret = open(cachePath.c_str(), 0); 
      if (ret == -1) {
          return -errno;
      }
    }
    else {
      cout << "\nOpening server file\n";
      ret = client.Open(_path, O_RDWR | O_CREAT | S_IRWXU);
      // if (ret != 0) return ret;
      std::string _buf;
      int size = 0;
      int offset = 0;
      ret = client.Read(_path, _buf, size, offset);
      // if (ret != 0) return ret;
      createLocalCacheFile(_path, _buf);
      string cachePath = getCacheFilePath(_path);
      ret = open(cachePath.c_str(), 0);
    }
    fi->fh = ret;
    return 0;
  }
  // Read
  int connect_grpc_fuse_read(const char *path, char *buf, size_t size, off_t offset,
                             struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect GRPC FUSE read ---\n";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    int ret, fd;
    if (fi == NULL)
    {
      fi = new fuse_file_info();
      fi->flags = O_RDONLY;
      fd = connect_grpc_fuse_open(path, fi);
    }
    else
    {
      fd = fi->fh;
    }

    if (fd == -1)
    {
      return -errno;
    }
    ret = pread(fd, buf, size, offset);

    if (ret == -1)
    {
      ret = -errno;
    }
    return ret;
  }

  int connect_grpc_fuse_create(const char *path, mode_t mode,
                               struct fuse_file_info *fi)
  {

    std::cout << "\n--- connect GRPC FUSE create ---\n";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    int ret, attrRet, errornum;
    ;
    const std::string _path(path);
    string cachePath = getCacheFilePath(_path);

    struct stat localAttr, serverAttr;
    bool isValidCache = true;

    int lstatValue = lstat(cachePath.c_str(), &localAttr);
    attrRet = client.GetAttr(_path, &serverAttr, errornum);
    int serverTime = serverAttr.st_mtime;
    int cacheTime = localAttr.st_mtime;
    if (serverTime > cacheTime) {
      isValidCache = false; 
    }
    if(attrRet!=0 ){
      cout << "\nOpening server file\n";
      ret = client.Open(_path, O_RDWR | O_CREAT);
      // if (ret != 0) return ret;
      std::string _buf;
      int size = 0;
      int offset = 0;
      ret = client.Read(_path, _buf, size, offset);
      // if (ret != 0) return ret;
      createLocalCacheFile(_path, _buf);
      string cachePath = getCacheFilePath(_path);
      ret = open(cachePath.c_str(), S_IRWXG | S_IRWXO | S_IRWXU, O_RDWR | O_CREAT);

    }
    if (isValidCache) {
      cout << "\nOpening cache file\n";
      string cachePath = getCacheFilePath(_path);
      ret = open(cachePath.c_str(), 0); 
      if (ret == -1) {
          return -errno;
      }
    }
    fi->fh = ret;
    return 0;
  }
  // Write
  int connect_grpc_fuse_write(const char *path, const char *buf, size_t size,
                              off_t offset, struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect GRPC FUSE write ---\n";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    std::string _buf(buf);
    string cachePath = getCacheFilePath(_path);
    fi->fh = open(cachePath.c_str(), O_RDWR | O_APPEND);
    int ret = pwrite(fi->fh, buf, size, offset);
    // TODO: dirty bit for release
    setDirty();
    if (ret == -1)
      return -errno;
    return ret;
  }

  int connect_grpc_fuse_statfs(const char *path, struct statvfs *buf)
  {
    std::cout << "\n--- connect_grpc_fuse_statfs ---\n";

    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret = statvfs(path, buf);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_flush(const char *path, struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect_grpc_fuse_flush ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret = close(dup(fi->fh));
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  // MkDir
  int connect_grpc_fuse_mkdir(const char *path, mode_t mode)
  {
    std::cout << "\n--- connect GRPC FUSE mkdir ---\n";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    int ret;
    ret = client.MkDir(_path, mode);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }
  // RmDir
  int connect_grpc_fuse_rmdir(const char *path)
  {
    std::cout << "\n--- connect GRPC FUSE rmdir ---\n";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    int ret;
    ret = client.RmDir(_path);
    if (ret == -1)
    {
      return -errno;
    }
    return 0;
  }

  int connect_grpc_fuse_release(const char *path, struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect_grpc_fuse_release ---\n";
  if (!isDirty()){
      int ret = close(fi->fh);
    if (ret == -1)
      return -errno;
    return 0;
  }
  else
  {
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const string _path(path);
    string cachePath = getCacheFilePath(_path);
    std::ifstream in(cachePath, std::ifstream::ate | std::ifstream::binary);
    in.seekg(0,std::ios::end);
    int size = in.tellg();
    in.seekg(0, std::ios::beg);
    string buf;
    buf.resize(size);;
    in.read(&buf[0], size);
    int ret = client.Write(_path, buf, size, 0);
    in.close();
    resetDirty();
  }
      
  }

  int connect_grpc_fuse_fsync(const char *path, int datasync, struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect_grpc_fuse_fsync ---\n";
    int ret;
    if (datasync)
    {
      ret = fdatasync(fi->fh);
      if (ret == -1)
      {
        return -errno;
      }
    }
    else
    {
      ret = fsync(fi->fh);
      if (ret == -1)
      {
        return -errno;
      }
    }

    return 0;
  }

#ifdef HAVE_XATTR
  int connect_grpc_fuse_setxattr(const char *path, const char *name, const char *value, size_t size, int flags)
  {
    std::cout << "\n--- connect_grpc_fuse_setxattr ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret;
#ifdef __APPLE__
    ret = setxattr(path, name, value, size, 0, flags);
#else
    ret = setxattr(path, name, value, size, flags);
#endif /* __APPLE__ */
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_getxattr(const char *path, const char *name, char *value, size_t size)
  {
    std::cout << "\n--- connect_grpc_fuse_getxattr ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();

    int ret;
#ifdef __APPLE__
    ret = getxattr(path, name, value, size, 0, XATTR_NOFOLLOW);
#else
    ret = getxattr(path, name, value, size);
#endif /* __APPLE__ */
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_listxattr(const char *path, char *list, size_t size)
  {
    std::cout << "\n--- connect_grpc_fuse_listxattr ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret;
#ifdef __APPLE__
    ret = listxattr(path, list, size, XATTR_NOFOLLOW);
#else
    ret = listxattr(path, list, size);
#endif /* __APPLE__ */
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_removexattr(const char *path, const char *name)
  {
    std::cout << "\n--- connect_grpc_fuse_removexattr ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret;
#ifdef __APPLE__
    ret = removexattr(path, name, XATTR_NOFOLLOW);
#else
    ret = removexattr(path, name);
#endif /* __APPLE__ */
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }
#endif /* HAVE_XATTR */

  int connect_grpc_fuse_opendir(const char *path, struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect_grpc_fuse_opendir ---\n";

    // path = Utility::constructRelativePath(path).c_str();

    // DIR* dir = opendir(path);

    // if (!dir) {
    //   return -errno;
    // }
    // fi->fh = (int64_t)dir;

    return 0;
  }

  int connect_grpc_fuse_releasedir(const char *path, struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect_grpc_fuse_releasedir ---\n";

    // path = Utility::constructRelativePath(path).c_str();

    //DIR *dir = (DIR *)fi->fh;

    //int ret = closedir(dir);
    // if (ret == -1)
    // {
    //   return -errno;
    // }

    return 0;
  }

  int connect_grpc_fuse_fsyncdir(const char *path, int datasync, struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect_grpc_fuse_fsyncdir ---\n";

    // path = Utility::constructRelativePath(path).c_str();
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret;
    // TODO:
    DIR *dir = opendir(path);
    if (!dir)
    {
      return -errno;
    }

    if (datasync)
    {
      ret = fdatasync(dirfd(dir));
      if (ret == -1)
      {
        return -errno;
      }
    }
    else
    {
      ret = fsync(dirfd(dir));
    }
    closedir(dir);
    return 0;
  }

  int connect_grpc_fuse_access(const char *path, int mode)
  {
    std::cout << "\n--- connect_grpc_fuse_access ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret = access(path, mode);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_ftruncate(const char *path, off_t length, struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect_grpc_fuse_ftruncate ---\n";
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret = truncate(path, length);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_fgetattr(const char *path, struct stat *buf, struct fuse_file_info *fi)
  {
    std::cout << "\n--- connect_grpc_fuse_fgetattr\n"
              << std::endl;
    
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret = fstat((int)fi->fh, buf);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

  int connect_grpc_fuse_lock(const char *path, struct fuse_file_info *fi, int cmd, struct flock *fl)
  {
    int ret = fcntl((int)fi->fh, cmd, fl);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }

#if !defined(__OpenBSD__)
  int connect_grpc_fuse_ioctl(const char *path, int cmd, void *arg, struct fuse_file_info *fi, unsigned int flags, void *data)
  {
    int ret = ioctl(fi->fh, cmd, arg);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }
#endif /* __OpenBSD__ */

#ifdef HAVE_FLOCK
  int connect_grpc_fuse_flock(const char *path, struct fuse_file_info *fi, int op)
  {
    int ret = flock(((int)fi->fh), op);
    if (ret == -1)
    {
      return -errno;
    }

    return 0;
  }
#endif /* HAVE_FLOCK */

#ifdef HAVE_FALLOCATE
  // TODO:
  int connect_grpc_fuse_fallocate(const char *path, int mode, off_t offset, off_t len, struct fuse_file_info *fi)
  {
    const string _path(path);
    path =getCacheFilePath(_path).c_str();
    int ret;
    int fd;
    (void)fi;

    if (mode)
    {
      return -EOPNOTSUPP;
    }

    if (fi == NULL)
    {
      fd = open(path, O_WRONLY);
    }
    else
    {
      fd = fi->fh;
    }

    if (fd == -1)
    {
      return -errno;
    }

    ret = fallocate((int)fi->fh, mode, offset, len);
    if (ret == -1)
    {
      return -errno;
    }

    if (fi == NULL)
    {
      close(fd);
    }

    return 0;
  }
#endif /* HAVE_FALLOCATE */

#ifdef HAVE_UTIMENSAT
  int connect_grpc_fuse_utimens(const char *path, const struct timespec ts[2])
  {
    cout << "\nutimens\n"; 

      // int ret = utimensat(0, path, ts, AT_SYMLINK_NOFOLLOW);
      // if (ret == -1)
      // {
      //   return -errno;
      // }

      return 0;
  }
#endif /* HAVE_UTIMENSAT */

  int connect_grpc_fuse_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
                                off_t offset, struct fuse_file_info *fi)
  {
    std::cout << "connect GRPC FUSE rmdir ---\n";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    // std::string _buf(buf);

    /*DIR *dp = opendir(path);
    if (dp == NULL) {
  return -errno;
    }
    struct dirent *de;

    (void) offset;
    (void) fi;

    while ((de = readdir(dp)) != NULL) {
        struct stat st;
        memset(&st, 0, sizeof(st));
        st.st_ino = de->d_ino;
        st.st_mode = de->d_type << 12;
        if (filler(buf, de->d_name, &st, 0))
            break;
    }
    closedir(dp);*/

    struct dirent de;
    int errornum = 0;
    std::vector<std::string> results;
    int ret = client.ReadDir(_path, results);
    if (ret != 0)
    {
      return -errornum;
    }

    for (auto result : results)
    {
      struct stat st;
      memset(&st, 0, sizeof(st));
      memcpy(&de, &result[0], result.size());
      st.st_ino = de.d_ino;
      st.st_mode = de.d_type << 12;
      if (filler(buf, de.d_name, &st, 0))
        break;
    }
    return 0;
  }
#ifdef __cplusplus
}
#endif
/*int main(){
    return 0;
}*/
