#pragma once
#include "LikesGainer.cpp"

#ifndef _LikesGainer_hpp
#define _LikesGainer_hpp

static void addLikesForVideo(std::vector<Video>& videoToAddLikes, const std::string& videoID, float countOfLikesToAdd);

#endif