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

string cacheRootPath = "/users/pmurugan/cache";
int dirtyBit = 0;

void createCacheDirectory() {
    fs::create_directories(cacheRootPath) == true 
        ? cout << "\n--- cache directory created! ---\n" 
        : cout << "\n--- Cache directory already exists on client side! ---\n";
}

string getCacheFilePath(string path) {
    // string filename = path.substr(path.find_last_of("/\\") + 1);
    string cachePath = cacheRootPath + path;
    return cachePath;
} 

bool localCopyExists(string path) {
    string cachePath = getCacheFilePath(path);
    return fs::exists(cachePath);
}

int createLocalCacheFile(string path, string contents) {
    cout << "\n--- creating local copy ---\n" ;
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
    return dirtyBit;
}
