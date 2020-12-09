#pragma once
#include <string>
#include "VideoData.cpp"

#ifndef _VideoData_hpp
#define _VideoData_hpp

static const std::vector<Video> &getFullVideoBase();
static void saveToFullVideoBase(const Video& addVideo);

#endif
