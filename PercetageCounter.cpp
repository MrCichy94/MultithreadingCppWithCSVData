#pragma once

#include <vector>

#include "DataBuilder.hpp"

class PercentageCounter{

public:
    static std::vector<std::pair<std::string,std::pair<float,float>>> countVotesRating(const std::vector<Video>& videos){

        std::vector<std::pair<std::string,std::pair<float,float>>> videosRatings;

        for(const auto& p : videos){

            std::string videoID = p.getVideoId();

            float likes = p.getLikes();
            float dislikes = p.getDislikes();
            float total = p.getLikes() + p.getDislikes();

            float positiveRate;
            if(likes != 0){
                positiveRate = likes/total;
            } else positiveRate = 0;

            float negativeRate;
            if(likes != 0){
                negativeRate = dislikes/total;
            } else negativeRate = 0;

            videosRatings.emplace_back(videoID, std::make_pair(positiveRate*100, negativeRate*100));
        }
        return videosRatings;
    }
};