#pragma once
#include "Video.cpp"

#ifndef _Video_hpp
#define _Video_hpp

const std::string &getVideoId();
void setVideoId(const std::string &videoId);

const std::string &getTrendingDate();
void setTrendingDate(const std::string &trendingDate);

const std::string &getChannelTitle();
void setChannelTitle(const std::string &channelTitle);

int getViews();
void setViews(int views);

int getLikes();
void setLikes(int likes);

int getDislikes();
void setDislikes(int dislikes);

int getComments();
void setComments(int comments);

#endif

