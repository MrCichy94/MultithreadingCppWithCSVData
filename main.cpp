#include <iostream>
#include <chrono>
#include <future>
#include <thread>

#include "URLCreator.hpp"
#include "PercetageCounter.hpp"


int main() {

    std::cout << "Threads: " << std::thread::hardware_concurrency() << std::endl;
    std::thread::id mainThread = std::this_thread::get_id();
    std::cout << "Main thread id: " << mainThread << std::endl;

    auto startTime = std::chrono::high_resolution_clock::now();

    auto videos = DataBuilder::addDataFromFileToVector("data.csv");

    auto finishTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> proccessTime = finishTime - startTime;

    std::cout << "Processing (reading data) time: " << proccessTime.count() << " s" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    auto videosURLs = URLCreator::createFullVideoURL(videos);

    auto finishTime2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> proccessTime2 = finishTime2 - finishTime;

    std::cout << "Processing (creating URLs) time: " << proccessTime2.count() << " s" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    auto videosRatings = PercentageCounter::countVotesRating(videos);

    auto finishTime3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> proccessTime3 = finishTime3 - finishTime2;

    std::cout << "Processing (creating ratings) time: " << proccessTime3.count() << " s" << std::endl;

    /* -------!!!------- TRY FUN WITH MULTI -------!!!------- */

    auto threadOne = std::async(std::launch::async, URLCreator::createFullVideoURL, videos);
    auto threadTwo = std::async(std::launch::async, PercentageCounter::countVotesRating, videos);

    std::cout << "----------------------------------------------" << std::endl;

    auto finishTime4 = std::chrono::high_resolution_clock::now();
    threadOne.get();
    threadTwo.get();
    auto finishTime5 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> proccessTime4 = finishTime5 - finishTime4;

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Processing (NORMAL) time: " << proccessTime3.count() + proccessTime2.count() << " s" << std::endl;
    std::cout << "Processing (MULTI) time: " << proccessTime4.count() << " s" << std::endl;
    std::cout << "2 THREADs WAS FASTER THAN 1 ABOUT: " << (proccessTime2.count()+proccessTime3.count())-proccessTime4.count() << " s" << std::endl;

    return 0;
}