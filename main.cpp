#include <iostream>
#include <chrono>
#include "URLCreator.hpp"
#include "PercetageCounter.hpp"


int main() {

    auto startTime = std::chrono::high_resolution_clock::now();

    auto videos = DataBuilder::addDataFromFileToVector("data.csv"); //final file is "data.csv"
    /* INFO :: 40k w czasie 0,16s | 80k w czasie 0,33s (dokument .csv, format 7 kolumn)
    int liczba = 0;
    for(const auto& p : videos){
        std::cout << "Rekord numer " << liczba << ". " << p.getVideoId() << std::endl;
        liczba++;
    }
    */

    auto finishTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> proccessTime = finishTime - startTime;

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Processing (reading data) time: " << proccessTime.count() << " s" << std::endl;

    auto videosURLs = URLCreator::createFullVideoURL(videos);

    auto finishTime2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> proccessTime2 = finishTime2 - finishTime;

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Processing (creating URLs) time: " << proccessTime2.count() << " s" << std::endl;
    std::cout << videosURLs[155] << std::endl;

    auto videosRatings = PercentageCounter::countVotesRating(videos);

    auto finishTime3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> proccessTime3 = finishTime3 - finishTime2;

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Processing (creating URLs) time: " << proccessTime3.count() << " s" << std::endl;
    std::cout << "Positive rating for this video: " << videosRatings[155].first << " %" << std::endl;

    return 0;
}
