#include <vector>
#include "Video.hpp"

class VideoData{

    std::vector<Video> fullVideoBase;
    std::vector<Video> idVideoVector;
    std::vector<Video> viewsVideoVector;

public:

    const std::vector<Video> &getFullVideoBase() const {return fullVideoBase;}
    void saveToFullVideoBase(Video addVideo) {
        VideoData::fullVideoBase.push_back(addVideo);
    }

    const std::vector<Video> &getIdVideoVector() const {return idVideoVector;}
    void saveToIdVideoVector(Video addVideo) {
        VideoData::idVideoVector.push_back(addVideo);
    }

    const std::vector<Video> &getViewsVideoVector() const {return viewsVideoVector;}
    void saveToViewsVideoVector(Video addVideo) {
        VideoData::viewsVideoVector.push_back(addVideo);
    }


};