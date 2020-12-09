#include <iostream>
#include <vector>
#include "DataReadBuilder.hpp"


int main() {


    auto *idVid = new Video("irda");
    auto *viewsVid = new Video(5);

    std::vector<Video> mojeChwilowe;
    mojeChwilowe.push_back(*viewsVid);

    VideoData readData;
    VideoData::saveToFullVideoBase(*viewsVid);

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Rozmiar tablicy: " << mojeChwilowe.size() << std::endl;

    for(const auto& p : mojeChwilowe){
        std::cout << "Wyswietlenia: " << p.getViews() << std::endl;
    }

    for(const auto& p : VideoData::getFullVideoBase()){
        std::cout << "Wyswietlenia z VideoData: " << p.getViews() << std::endl;
    }

    std::cout << "----------------------------------------------" << std::endl;

    auto videos = DataReadBuilder::addDataFromFileToVector("10z80k_przeklad.csv");


    return 0;
}
