#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Video.hpp"



class DataBuilder{

    //static because we dont need instance of this class, dont need a diffrent objects, diffrent behavior.
    static std::vector<std::string> readDataFromCSVFile(const std::string& fileInput){

        std::vector<std::string> singleVideoValues;
        std::ifstream file(fileInput);

        try {
            std::string lineInFile;
            std::string field;

            while (file) {

                std::getline(file, lineInFile);
                std::istringstream ss(lineInFile);
                while (std::getline(ss, field, ';')) {
                    singleVideoValues.emplace_back(field);
                }
            }
            file.close();
        } catch (const std::runtime_error& e){}
        return singleVideoValues;
    }

public:

    static std::vector<Video> addDataFromFileToVector(const std::string& fileInput){

        static std::vector<Video> videos;

        auto videoData = readDataFromCSVFile(fileInput);

        try {
            for(auto i = 0U; i < videoData.size(); i += 7) {

                auto videoId = videoData[i];
                auto trendingDate = videoData[i + 1];
                auto channelTitle = videoData[i + 2];

                auto views = videoData[i + 3];
                auto viewsNum = std::strtoul(views.c_str(), nullptr, 10);

                auto likes = videoData[i + 4];
                auto likesNum = std::strtoul(likes.c_str(), nullptr, 10);

                auto dislikes = videoData[i + 5];
                auto dislikesNum = std::strtoul(dislikes.c_str(), nullptr, 10);

                auto commentCount = videoData[i + 6];
                auto commentCountNum = std::strtoul(commentCount.c_str(), nullptr, 10);

                videos.emplace_back(videoId, trendingDate, channelTitle,
                                    viewsNum, likesNum, dislikesNum, commentCountNum);
            }
        } catch (const std::runtime_error& e){}
        return videos;
    }
};