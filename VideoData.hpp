#include <string>
#include "VideoData.cpp"

#ifndef _VideoData_hpp
#define _VideoData_hpp

const std::vector<Video> &getFullVideoBase();
void saveToFullVideoBase(const std::vector<Video> &fullVideoBase);

const std::vector<Video> &getIdVideoVector();
void saveToIdVideoVector(const std::vector<Video> &idVideoVector);

const std::vector<Video> &getViewsVideoVector();
void saveToViewsVideoVector(const std::vector<Video> &viewsVideoVector);

#endif