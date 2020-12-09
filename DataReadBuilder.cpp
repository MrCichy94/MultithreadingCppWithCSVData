#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include "VideoData.hpp"

class DataReadBuilder{

    static std::vector<std::string> readDataFromCSVFile(const std::string& fileInput){

        std::vector<std::string> singleVideoValues;
        std::ifstream file(fileInput);

        if(!file) {
            throw std::runtime_error("File open error!");
        }

        std::string lineInFile;
        std::string field;

        while(file){

            std::getline(file,lineInFile);
            std::istringstream ss(lineInFile);
            while(std::getline(ss, field, ',')){
                singleVideoValues.emplace_back(field);
            }
        }
        return singleVideoValues;
    }

public:

    static std::vector<Video> addDataFromFileToVector(const std::string& fileInput){

        auto videoData = readDataFromCSVFile(fileInput);

        if(videoData.size() % 9) {
            throw std::runtime_error("Data format error!");
        }

        std::vector<Video> videos;
        for(auto i = 0U; i < videoData.size(); i += 8) {

            auto videoId = videoData[i];
            auto trendingDate = videoData[i + 1];
            auto title = videoData[i + 2];
            auto channelTitle = videoData[i + 3];

            auto views = videoData[i + 4];
            auto viewsNum = std::stoi(views);

            auto likes = videoData[i + 5];
            auto likesNum = std::stoi(likes);

            auto dislikes = videoData[i + 6];
            auto dislikesNum = std::stoi(dislikes);

            auto commentCount = videoData[i + 7];
            auto commentCountNum = std::stoi(commentCount);

            auto description = videoData[i + 8];

            videos.emplace_back(videoId, trendingDate, title, channelTitle,
                                viewsNum, likesNum, dislikesNum, commentCountNum, description);

        }
        return videos;
    }

};