#pragma once
#include "Video.cpp"

#ifndef _Video_hpp
#define _Video_hpp

const std::string &getVideoId();
const std::string &getTrendingDate();
const std::string &getChannelTitle();
float getViews();
float getLikes();
void setLikes(float likes);
float getDislikes();
float getComments();

#endif

