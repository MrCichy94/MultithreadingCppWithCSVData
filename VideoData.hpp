#include <string>
#include "VideoData.cpp"

#ifndef _VideoData_hpp
#define _VideoData_hpp

const std::vector<Video> &getFullVideoBase();
void saveToFullVideoBase(const std::vector<Video> &fullVideoBase);

#endif