#pragma once

#include <vector>

#include "DataBuilder.hpp"

class URLCreator{

public:

    //static because we dont need instance of this class, dont need a diffrent objects, diffrent behavior.
    static std::vector<std::string> createFullVideoURL(const std::vector<Video>& videos){

        std::vector<std::string> videosURLs;

        videosURLs.reserve(videos.size());

        for(const auto& p : videos){
            videosURLs.emplace_back("https://www.youtube.com/watch?v=" + p.getVideoId());
        }
        std::cout << "urlCreator is me!" << std::endl;
        return videosURLs;
    }
};

