#pragma once
#include <string>
#include <ostream>

class Video{

private:

    std::string videoId;
    std::string trendingDate;
    std::string channelTitle;
    float views;
    float likes;
    float dislikes;
    float comments;

public:

    Video(std::string videoId, std::string trendingDate, std::string channelTitle, float views,
          float likes, float dislikes, float comments) : videoId(std::move(videoId)), trendingDate(std::move(trendingDate)),
                                            channelTitle(std::move(channelTitle)), views(views), likes(likes), dislikes(dislikes),
                                            comments(comments) {}

    Video(const Video& obj) = default;
    Video(Video&& obj) = default;
    Video& operator = (const Video& obj) = default;
    Video& operator = (Video&& obj) = default;
    ~Video()= default;

    const std::string &getVideoId() const {return videoId;}
    const std::string &getTrendingDate() const {return trendingDate;}
    const std::string &getChannelTitle() const {return channelTitle;}
    float getViews() const {return views;}
    float getLikes() const {return likes;}
    void setLikes(float likes) {Video::likes = likes;}
    float getDislikes() const {return dislikes;}
    float getComments() const {return comments;}

};