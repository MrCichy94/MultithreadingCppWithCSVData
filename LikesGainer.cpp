#pragma once

#include "DataBuilder.hpp"

class LikesGainer {

public:

    static void addLikesForVideo(std::vector<Video>& videoToAddLikes, const std::string& videoID, float countOfLikesToAdd) {

        float inputLikes = 0;
        float outputLikes = 0;

        for(auto& p : videoToAddLikes) {
            if(p.getVideoId() == videoID) {
                inputLikes = p.getLikes();
                outputLikes = inputLikes + countOfLikesToAdd;
                p.setLikes(outputLikes);
                break; //because, when i look to data archive i found more than 1 IDs same record! I dont want to merge the data. I need as many record as possible.
            }
        }
        std::cout << countOfLikesToAdd << " likes added to video: " << videoID << std::endl;
        std::cout << "Likes was increase from: " << inputLikes << " to: " << outputLikes << std::endl;
        std::cout << "Thank you for a successful transaction!" << std::endl;
    }

};