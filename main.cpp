#include <iostream>
#include <vector>
#include "VideoData.hpp"


int main() {

    auto *idVid = new Video("irda");
    auto *viewsVid = new Video(5);

    std::vector<Video> mojeChwilowe;
    mojeChwilowe.push_back(*viewsVid);

    //VideoData::saveToViewsVideoVector(*viewsVid); //!static needed, so to change

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Rozmiar tablicy: " << mojeChwilowe.size() << std::endl;

    for(const auto& p : mojeChwilowe){
        std::cout << "Wyswietlenia: " << p.getViews();
    }

    return 0;
}
