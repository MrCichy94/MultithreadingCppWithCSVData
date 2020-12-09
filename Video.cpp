#include <string>

class Video{

public:
    //constructors
    Video (std::string videoId, std::string trendingDate, std::string title,
           std::string channelTitle, int views, int likes, int dislikes, int comments,
           std::string description) : video_id(std::move(videoId)), trending_date(std::move(trendingDate)), title(std::move(title)),
                                             channel_title(std::move(channelTitle)), views(views), likes(likes), dislikes(dislikes),
                                             comments(comments), description(std::move(description)) {}
    explicit Video (std::string videoId) : video_id(std::move(videoId)) {}
    explicit Video (const int &views) : views(views) {}

//getters&setters
    const std::string &getVideoId() const {return video_id;}
    void setVideoId(const std::string &videoId) {video_id = videoId;}

    const std::string &getTrendingDate() const {return trending_date;}
    void setTrendingDate(const std::string &trendingDate) {trending_date = trendingDate;}

    const std::string &getTitle() const {return title;}
    void setTitle(const std::string &title) {Video::title = title;}

    const std::string &getChannelTitle() const {return channel_title;}
    void setChannelTitle(const std::string &channelTitle) {channel_title = channelTitle;}

    int getViews() const {return views;}
    void setViews(int views) {Video::views = views;}

    int getLikes() const {return likes;}
    void setLikes(int likes) {Video::likes = likes;}

    int getDislikes() const {return dislikes;}
    void setDislikes(int dislikes) {Video::dislikes = dislikes;}

    int getComments() const {return comments;}
    void setComments(int comments) {Video::comments = comments;}

    const std::string &getDescription() const {return description;}
    void setDescription(const std::string &description) {Video::description = description;}

private:
    std::string video_id;
    std::string trending_date;
    std::string title;
    std::string channel_title;
    int views;
    int likes;
    int dislikes;
    int comments;
    std::string description;
};