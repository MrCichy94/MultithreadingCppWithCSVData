#pragma once
#include <string>

class Video{

private:

    std::string videoId;
    std::string trendingDate;
    std::string channelTitle;
    int views;
    int likes;
    int dislikes;
    int comments;

public:

    Video(std::string videoId, std::string trendingDate, std::string channelTitle, int views,
          int likes, int dislikes, int comments) : videoId(std::move(videoId)), trendingDate(std::move(trendingDate)),
                                            channelTitle(std::move(channelTitle)), views(views), likes(likes), dislikes(dislikes),
                                            comments(comments) {}

    const std::string &getVideoId() const {return videoId;}
    void setVideoId(const std::string &videoId) {Video::videoId = videoId;}

    const std::string &getTrendingDate() const {return trendingDate;}
    void setTrendingDate(const std::string &trendingDate) {Video::trendingDate = trendingDate;}

    const std::string &getChannelTitle() const {return channelTitle;}
    void setChannelTitle(const std::string &channelTitle) {Video::channelTitle = channelTitle;}

    int getViews() const {return views;}
    void setViews(int views) {Video::views = views;}

    int getLikes() const {return likes;}
    void setLikes(int likes) {Video::likes = likes;}

    int getDislikes() const {return dislikes;}
    void setDislikes(int dislikes) {Video::dislikes = dislikes;}

    int getComments() const {return comments;}
    void setComments(int comments) {Video::comments = comments;}

};