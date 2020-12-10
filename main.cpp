#include <iostream>
#include <vector>
#include <chrono>
#include "DataReadBuilder.hpp"


int main() {

/*
    auto *idVid = new Video("irda");
    auto *viewsVid = new Video(5);

    std::vector<Video> mojeChwilowe;
    mojeChwilowe.push_back(*viewsVid);

    DataReadBuilder readData;
    DataReadBuilder::saveToFullVideoBase(*viewsVid);

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Rozmiar tablicy: " << mojeChwilowe.size() << std::endl;

    for(const auto& p : mojeChwilowe){
        std::cout << "Wyswietlenia: " << p.getViews() << std::endl;
    }

    for(const auto& p : DataReadBuilder::getFullVideoBase()){
        std::cout << "Wyswietlenia z VideoData: " << p.getViews() << std::endl;
    }
*/

    std::cout << "----------------------------------------------" << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();

    auto videos = DataReadBuilder::addDataFromFileToVector("przyklad.csv"); //final file is "data.csv"

    int liczba = 0;
    for(const auto& p : videos){
        std::cout << "Rekord numer " << liczba << ". " << p.getChannelTitle() << std::endl;
        liczba++;
    }

    auto finishTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> proccessTime = finishTime - startTime;

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Elapsed time: " << proccessTime.count() << " s" << std::endl;

    return 0;
}
