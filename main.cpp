#include <iostream>
#include <vector>
#include "VideoData.hpp"


int main() {

    auto *idVid = new Video("irda");
    auto *viewsVid = new Video(5);

    std::vector<Video> mojeChwilowe;
    mojeChwilowe.push_back(*viewsVid);

    VideoData readData;
    readData.saveToFullVideoBase(*viewsVid);

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Rozmiar tablicy: " << mojeChwilowe.size() << std::endl;

    for(const auto& p : mojeChwilowe){
        std::cout << "Wyswietlenia: " << p.getViews() << std::endl;
    }

    for(const auto& p : readData.getFullVideoBase()){
        std::cout << "Wyswietlenia z VideoData: " << p.getViews();
    }


    return 0;
}
