#include <vector>
#include "Video.hpp"

class VideoData{

private:

    static std::vector<Video> fullVideoBase;

public:

    static const std::vector<Video> &getFullVideoBase() {return fullVideoBase;}
    static void saveToFullVideoBase(const Video& addVideo) {
        VideoData::fullVideoBase.push_back(addVideo);
    }

};