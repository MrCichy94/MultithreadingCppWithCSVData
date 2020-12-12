#include <iostream>
#include <chrono>
#include <future>
#include <thread>

#include "URLCreator.hpp"
#include "PercetageCounter.hpp"


int main() {

    std::thread::id mainThread = std::this_thread::get_id();
    std::cout << "Main thread id: " << mainThread << std::endl;

    auto startTime = std::chrono::high_resolution_clock::now();

    auto videos = DataBuilder::addDataFromFileToVector("data.csv");

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
    std::cout << "Processing (creating ratings) time: " << proccessTime3.count() << " s" << std::endl;
    std::cout << "Positive rating for this video: " << videosRatings[112].second.first << " %" << std::endl;

    /* -------!!!------- TRY FUN WITH MULTI -------!!!------- */

    std::thread threadOne(&URLCreator::createFullVideoURL,videos);
    std::thread threadTwo(&PercentageCounter::countVotesRating,videos);
    std::cout << threadOne.get_id() << std::endl;
    std::cout << threadTwo.get_id() << std::endl;
    threadOne.join();
    threadTwo.join();
    auto finishTime4 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> proccessTime4 = finishTime4 - finishTime3;

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Processing (NORMAL) time: " << proccessTime3.count() + proccessTime2.count() << " s" << std::endl;
    std::cout << "Processing (ASYNC) time: " << proccessTime4.count() << " s" << std::endl;
    std::cout << "2 THREADs WAS FASTER THAN 1 ABOUT: " << (proccessTime2.count()+proccessTime3.count())-proccessTime4.count() << " s" << std::endl;

    std::cout << "This is a debug message, threads: " << std::thread::hardware_concurrency() << std::endl;
    return 0;
}