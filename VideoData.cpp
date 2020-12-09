#include <utility>
#include <vector>
#include "Video.hpp"

class VideoData{

    std::vector<Video> fullVideoBase;

public:

    VideoData()= default;

    const std::vector<Video> &getFullVideoBase() const {return fullVideoBase;}
    void saveToFullVideoBase(Video addVideo) {
        VideoData::fullVideoBase.push_back(addVideo);
    }

};