#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <experimental/filesystem>

#include "wiscAFS.grpc.pb.h"

using namespace std;
namespace fs = experimental::filesystem;

string cacheRootPath = "/users/pmurugan/cache/tmp/ps/";
int dirtyBit = 0;

void createCacheDirectory() {
    fs::create_directories(cacheRootPath) == true ? cout << "\ncache directory created!\n" : cout << "\nCache directory already exists on client side !\n";
}
bool localCopyExists(string path) {
    string filename = path.substr(path.find_last_of("/\\") + 1);
    string cachePath = cacheRootPath + filename;
    cout << fs::exists(cachePath);
    return fs::exists(cachePath);
}

string getCacheFilePath(string path) {
    string filename = path.substr(path.find_last_of("/\\") + 1);
    string cachePath = cacheRootPath + filename;
    //  cout << "\ncache path ---> " <<  cachePath <<endl;
    return cachePath;
} 

int createLocalCacheFile(string path, string contents) {
    // if (!localCopyExists(path)) {
        cout << "\ncreating local copy\n" ;
        string cachePath = getCacheFilePath(path);

        std::ofstream tempfile(cachePath);
        tempfile << contents; 
        tempfile.close();
}

void setDirty(){
    dirtyBit=1;
}
void resetDirty(){
    dirtyBit=0;
}

int isDirty(){
    if(dirtyBit==1)
        return 1;
    else    
        return 0;
}
