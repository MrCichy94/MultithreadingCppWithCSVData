#pragma once
#include "Video.cpp"

#ifndef _Video_hpp
#define _Video_hpp

const std::string &getVideoId();
const std::string &getTrendingDate();
const std::string &getChannelTitle();
int getViews();
int getLikes();
void setLikes(float likes);
int getDislikes();
int getComments();

#endif

