#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "VideoData.hpp"

class DataReadBuilder{

    static std::vector<std::string> readDataFromCSVFile(const std::string& fileInput){

        std::ifstream file(fileInput);
        std::vector<std::string> singleVideoValues;

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

        for(auto i = 0U; i < videoData.size(); i += 8) {
            std::string video_id = videoData[i];
            std::string trending_date = videoData[i + 1];
            std::string title = videoData[i + 2];
            std::string channel_title = videoData[i + 3];
            std::string views = videoData[i + 4];
            std::string likes = videoData[i + 5];
            std::string dislikes = videoData[i + 6];
            std::string comment_count = videoData[i + 7];
            std::string description = videoData[i + 8];

            auto *singleVideoToAdd = new Video(video_id, trending_date, title, channel_title,
                                                std::stoi(views), std::stoi(likes), std::stoi(dislikes),
                                                std::stoi(comment_count), description);
            VideoData singleVideoToSave;
            VideoData::saveToFullVideoBase(*singleVideoToAdd);
        }
        return VideoData::getFullVideoBase();
    }

};