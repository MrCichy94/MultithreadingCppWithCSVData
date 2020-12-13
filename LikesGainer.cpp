#pragma once

#include "DataBuilder.hpp"

class LikesGainer {

public:
    //to tak nie zagra, on powinien przyjąć id do konkretego video i jemu dodac lajki. Pomysl jutro.
    static void addLikesForVideo(std::vector<std::pair<std::string,std::pair<float,float>>>& videoToAddLikes, float countOfLikesToAdd) {

        for(auto p : videoToAddLikes) {
            float inputLikes = p.second.first
        }
        /*
        float inputLikes = videoToAddLikes.
        videoToAddLikes.setLikes(inputLikes + countOfLikesToAdd);
        std::cout << countOfLikesToAdd << " likes added to video: " << videoToAddLikes.getLikes() << std::endl;
        std::cout << "Likes was increase from: " << inputLikes << " to: " << videoToAddLikes.getLikes() << std::endl;
        std::cout << "Thank you for a successful transaction!" << std::endl;
         */
    }

};