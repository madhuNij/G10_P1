#include <grpc++/grpc++.h>
#include "./connect_grpc_fuse.h"
#include "wiscAFS_client.h"
#include <fuse.h>
#ifdef __cplusplus
extern "C" {
#endif

// all of your legacy C code here
//GetAttr
int connect_grpc_fuse_getattr(const char *path, struct stat *buf)
{
    string hostport;
    int errornum;
    std::cout << "connect GRPC FUSE getattr" << std::endl;
    hostport = "128.105.144.70:50051";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    std::memset(buf, 0, sizeof(struct stat));
    int ret = client.GetAttr(_path, buf, errornum);
    if (ret == -1) {
      cout<<"\nerrornum "<<errornum;
        return -errornum;
    }

    return 0;
}

//lstat
int connect_grpc_fuse_lstat(const char* path, struct stat* buf) {
  std::cout << "\nconnect_grpc_fuse_lstat"<< std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  memset(buf, 0, sizeof(struct stat));
  if (lstat(path, buf) == -1) return -errno;

  return 0;
}

//readlink
int connect_grpc_fuse_readlink(const char* path, char* buf, size_t bufsiz) {
  std::cout <<  "\nconnect_grpc_fuse_readlink" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret = readlink(path, buf, bufsiz);
  if (ret == -1) {
    return -errno;
  }
  buf[ret] = 0;

  return 0;
}

//mknod
int connect_grpc_fuse_mknod(const char* path, mode_t mode, dev_t dev) {
  std::cout << "\nconnect_grpc_fuse_mknod" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret = mknod(path, mode, dev);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

//unlink
int connect_grpc_fuse_unlink(const char* path) {
  std::cout  << "\nconnect_grpc_fuse_unlink" << std::endl;
  string hostport = "128.105.144.70:50051";
  WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
 // std::string _path = Utility::constructRelativePath(path);
  int ret;
//   // delete server
   ret = client.Unlink(path);
//   // delete local
//   std::string path_str(_path);
//   std::unordered_map<std::string, std::string> cache = Cache::get_local_cache(cacheFile);
//   std::string sha_path = Cache::get_hash_path(path_str);
//   std::string local_cache_file = fsRootPath + "/" + sha_path;

  if (ret == -1) {
    return -errno;
  }

//   cache.erase(_path);
//   Cache::fsync_cache(cacheFile, cache);

  return 0;
}


//symlink
int connect_grpc_fuse_symlink(const char* target, const char* linkpath) {
  std::cout << "\nconnect_grpc_fuse_symlink" << std::endl;

  int ret = symlink(target, linkpath);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_rename(const char* oldpath, const char* newpath) {
  std::cout << "\nconnect_grpc_fuse_rename" << std::endl;

  int ret = rename(oldpath, newpath);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_link(const char* oldpath, const char* newpath) {
  std::cout <<"\nconnect_grpc_fuse_link" << std::endl;

  int ret = link(oldpath, newpath);
  if (ret < 0) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_chmod(const char* path, mode_t mode) {
  std::cout <<"\nconnect_grpc_fuse_chmod" << std::endl;

 // path = Utility::constructRelativePath(path).c_str();

  int ret = chmod(path, mode);
  if (ret < 0) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_chown(const char* path, uid_t owner, gid_t group) {
  std::cout <<"\nconnect_grpc_fuse_chown" <<std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret = chown(path, owner, group);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_truncate(const char* path, off_t length) {
  std::cout <<"\nconnect_grpc_fuse_truncate" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret = truncate(path, length);
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
    ret = client.Open(_path, O_RDWR | O_CREAT | S_IRWXU);
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
    cout<<"buffer contents: "<<_buf;
    if (ret == -1) {
        ret = -errno;
    }

    return ret;
}

int connect_grpc_fuse_create(const char *path, mode_t mode,
                      struct fuse_file_info *fi){
    
    string hostport;
    std::cout << "connect GRPC FUSE read" << std::endl;
    hostport = "128.105.144.70:50051";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    int ret;
    ret = client.Open(_path, O_RDWR | O_CREAT);
    if (ret == -1) {
        return -errno;
    }
    /*int numBytes;
    std::string buf;
    ret = client.Read(_path, buf, numBytes, buf);
    if (ret == -1) {
        return -errno;
    }*/
    return 0; 
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

int connect_grpc_fuse_statfs(const char* path, struct statvfs* buf) {
  std::cout << "\nconnect_grpc_fuse_statfs" << std::endl;

 // const char* _path = Utility::constructRelativePath(path).c_str();

  int ret = statvfs(path, buf);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_flush(const char* path, struct fuse_file_info* fi) {
  std::cout << "\nconnect_grpc_fuse_flush" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret = close(dup(fi->fh));
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

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

int connect_grpc_fuse_release(const char* path, struct fuse_file_info* fi) {
  std::cout <<"\nconnect_grpc_fuse_release" << std::endl;

  //std::string _path = Utility::constructRelativePath(path).c_str();

  int ret;
  // int numOfBytes;
  // long timestamp;
  // std::string path_str(path);

  ret = close(fi->fh);
  if (ret == -1) {
    return -errno;
  }
  return 0;
}

int connect_grpc_fuse_fsync(const char* path, int datasync, struct fuse_file_info* fi) {
  std::cout <<"\nconnect_grpc_fuse_fsync" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret;
  if (datasync) {
    ret = fdatasync(fi->fh);
    if (ret == -1) {
      return -errno;
    }
  } else {
    ret = fsync(fi->fh);
    if (ret == -1) {
      return -errno;
    }
  }

  return 0;
}



#ifdef HAVE_XATTR
int connect_grpc_fuse_setxattr(const char* path, const char* name, const char* value, size_t size, int flags) {
  std::cout <<"\nconnect_grpc_fuse_setxattr" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret;
#ifdef __APPLE__
  ret = setxattr(path, name, value, size, 0, flags);
#else
  ret = setxattr(path, name, value, size, flags);
#endif /* __APPLE__ */
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_getxattr(const char* path, const char* name, char* value, size_t size) {
  std::cout << "\nconnect_grpc_fuse_getxattr" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret;
#ifdef __APPLE__
  ret = getxattr(path, name, value, size, 0, XATTR_NOFOLLOW);
#else
  ret = getxattr(path, name, value, size);
#endif /* __APPLE__ */
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_listxattr(const char* path, char* list, size_t size) {
  std::cout << "\nconnect_grpc_fuse_listxattr" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret;
#ifdef __APPLE__
  ret = listxattr(path, list, size, XATTR_NOFOLLOW);
#else
  ret = listxattr(path, list, size);
#endif /* __APPLE__ */
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_removexattr(const char* path, const char* name) {
  std::cout << "\nconnect_grpc_fuse_removexattr" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret;
#ifdef __APPLE__
  ret = removexattr(path, name, XATTR_NOFOLLOW);
#else
  ret = removexattr(path, name);
#endif /* __APPLE__ */
  if (ret == -1) {
    return -errno;
  }

  return 0;
}
#endif /* HAVE_XATTR */

int connect_grpc_fuse_opendir(const char* path, struct fuse_file_info* fi) {
  std::cout <<"\nconnect_grpc_fuse_opendir" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  DIR* dir = opendir(path);

  if (!dir) {
    return -errno;
  }
  fi->fh = (int64_t)dir;

  return 0;
}

int connect_grpc_fuse_releasedir(const char* path, struct fuse_file_info* fi) {
  std::cout << "\nconnect_grpc_fuse_releasedir" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  DIR* dir = (DIR*)fi->fh;

  int ret = closedir(dir);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_fsyncdir(const char* path, int datasync, struct fuse_file_info* fi) {
  std::cout << "\nconnect_grpc_fuse_fsyncdir" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret;
  // TODO:
  DIR* dir = opendir(path);
  if (!dir) {
    return -errno;
  }

  if (datasync) {
    ret = fdatasync(dirfd(dir));
    if (ret == -1) {
      return -errno;
    }
  } else {
    ret = fsync(dirfd(dir));
    std::cout <<"before: " << path << std::endl;
    //ath = Utility::constructRelativePath(path).c_str();
    std::cout <<"after: " << path << std::endl;
  }
  closedir(dir);
  return 0;
}

int connect_grpc_fuse_access(const char* path, int mode) {
  std::cout <<"\nconnect_grpc_fuse_access" << std::endl;
  std::cout << "path: " << path << std::endl;
//   std::string _path = Utility::constructRelativePath(path);

//   std::string local_cache_dir(fsRootPath);
//   std::unordered_map<std::string, std::string> cache = Cache::get_local_cache(cacheFile);
//   std::string sha_path = Cache::get_hash_path(_path);
//   std::string local_cache_file = local_cache_dir + "/" + sha_path;

//   int ret = access(local_cache_file.c_str(), mode) || access(path, mode);
  int ret = access(path, mode);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_ftruncate(const char* path, off_t length, struct fuse_file_info* fi) {
  std::cout << "\nconnect_grpc_fuse_ftruncate" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();

  int ret = truncate(path, length);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_fgetattr(const char* path, struct stat* buf, struct fuse_file_info* fi) {
  std::cout << "\nconnect_grpc_fuse_fgetattr" << std::endl;

  //path = Utility::constructRelativePath(path).c_str();
  cout<<" path in fgetaatr "<<path.c_str();
  int ret = fstat((int)fi->fh, buf);
  if (ret == -1) {
    cout<<"\nin if ";
    return -errno;
  }

  return 0;
}

int connect_grpc_fuse_lock(const char* path, struct fuse_file_info* fi, int cmd, struct flock* fl) {
//   std::cout << yellow << "\nconnect_grpc_fuse_lock" << reset << std::endl;

//   path = Utility::constructRelativePath(path).c_str();

  int ret = fcntl((int)fi->fh, cmd, fl);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}

#if !defined(__OpenBSD__)
int connect_grpc_fuse_ioctl(const char* path, int cmd, void* arg, struct fuse_file_info* fi, unsigned int flags, void* data) {
//   std::cout << yellow << "\nconnect_grpc_fuse_ioctl" << reset << std::endl;

//   path = Utility::constructRelativePath(path).c_str();

  int ret = ioctl(fi->fh, cmd, arg);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}
#endif /* __OpenBSD__ */

#ifdef HAVE_FLOCK
int connect_grpc_fuse_flock(const char* path, struct fuse_file_info* fi, int op) {
//   std::cout << yellow << "\nconnect_grpc_fuse_flock" << reset << std::endl;

//   path = Utility::constructRelativePath(path).c_str();

  int ret = flock(((int)fi->fh), op);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}
#endif /* HAVE_FLOCK */

#ifdef HAVE_FALLOCATE
// TODO:
int connect_grpc_fuse_fallocate(const char* path, int mode, off_t offset, off_t len, struct fuse_file_info* fi) {
//   std::cout << yellow << "\nconnect_grpc_fuse_fallocate" << reset << std::endl;

//   path = Utility::constructRelativePath(path).c_str();

  int ret;
  int fd;
  (void)fi;

  if (mode) {
    return -EOPNOTSUPP;
  }

  if (fi == NULL) {
    fd = open(path, O_WRONLY);
  } else {
    fd = fi->fh;
  }

  if (fd == -1) {
    return -errno;
  }

  ret = fallocate((int)fi->fh, mode, offset, len);
  if (ret == -1) {
    return -errno;
  }

  if (fi == NULL) {
    close(fd);
  }

  return 0;
}
#endif /* HAVE_FALLOCATE */

#ifdef HAVE_UTIMENSAT
int connect_grpc_fuse_utimens(const char* path, const struct timespec ts[2]) {
//   std::cout << yellow << "\nconnect_grpc_fuse_utimens" << reset << std::endl;

//   path = Utility::constructRelativePath(path).c_str();

  /* don't use utime/utimes since they follow symlinks */
  // TODO:
  int ret = utimensat(0, path, ts, AT_SYMLINK_NOFOLLOW);
  if (ret == -1) {
    return -errno;
  }

  return 0;
}
#endif /* HAVE_UTIMENSAT */


int connect_grpc_fuse_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
                       off_t offset, struct fuse_file_info *fi)
{
    string hostport;
    std::cout << "connect GRPC FUSE rmdir" << std::endl;
    hostport = "128.105.144.70:50051";
    WiscAFSClient client(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));
    const std::string _path(path);
    //std::string _buf(buf);

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
    if (ret != 0) {
        return -errornum;
    }

    for (auto result : results) {
        struct stat st;
        memset(&st, 0, sizeof(st));
        memcpy(&de, &result[0], result.size());
        st.st_ino = de.d_ino;
        st.st_mode = de.d_type << 12;
        std::cout << "de.d_name: " << de.d_name << std::endl;
        if (filler(buf, de.d_name, &st, 0)) break;
    }
    return 0;
}
#ifdef __cplusplus
}
#endif
/*int main(){
    return 0;
}*/
