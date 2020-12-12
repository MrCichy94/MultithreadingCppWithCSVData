#pragma once
#include <string>
#include <ostream>

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

    Video(const Video& obj) : videoId(obj.videoId), trendingDate(obj.trendingDate), channelTitle(obj.channelTitle),
                            views(obj.views), likes(obj.likes), dislikes(obj.dislikes), comments(obj.comments) {}

    Video(Video&& obj) noexcept : videoId(std::move(obj.videoId)), trendingDate(std::move(obj.trendingDate)), channelTitle(std::move(obj.channelTitle)),
                         views(obj.views), likes(obj.likes), dislikes(obj.dislikes), comments(obj.comments) {}

    Video& operator = (const Video &obj) {
        std::cout << "copy assignment" << std::endl;
        return *this;
    }
    Video& operator = (Video &&obj)  noexcept {
        std::cout << "move assignment" << std::endl;
        return *this;
    }

    ~Video(){}


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