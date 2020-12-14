#include <iostream>
#include <chrono>
#include <future>
#include <thread>

#include "URLCreator.hpp"
#include "PercetageCounter.hpp"
#include "LikesGainer.hpp"


int main() {

    std::cout << "DEBUG MSG: Threads: " << std::thread::hardware_concurrency() << std::endl;
    std::thread::id mainThread = std::this_thread::get_id();
    std::cout << "DEBUG MSG: Main thread id: " << mainThread << std::endl;

    /* -------!!!------- TRY FUN WITH 1 THREAD RIDE -------!!!------- */

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

    auto videoID = URLCreator::getVideoIDbyNumberInVector(videos, 3);
    LikesGainer::addLikesForVideo(videos, videoID, 1000);

    /* -------!!!------- TRY FUN WITH ASYNC -------!!!------- */

    auto threadOne = std::async(std::launch::async, URLCreator::createFullVideoURL, videos);
    auto threadTwo = std::async(std::launch::async, PercentageCounter::countVotesRating, videos);

    std::cout << "----------------------------------------------" << std::endl;

    auto finishTime4 = std::chrono::high_resolution_clock::now();
    threadOne.get();
    threadTwo.get();
    auto finishTime5 = std::chrono::high_resolution_clock::now();

    /* -------!!!------- TRY FUN WITH MULTI -------!!!------- */

    std::thread first(URLCreator::createFullVideoURL, videos);
    std::thread second(PercentageCounter::countVotesRating, videos);

    std::cout << "----------------------------------------------" << std::endl;

    auto finishTime6 = std::chrono::high_resolution_clock::now();
    first.join();
    second.join();
    auto finishTime7 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> proccessTime4 = finishTime5 - finishTime4;
    std::chrono::duration<double> proccessTime5 = finishTime7 - finishTime6;

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Processing (NORMAL) time: " << proccessTime3.count() + proccessTime2.count() << " s" << std::endl;
    std::cout << "Processing (ASYNC) time: " << proccessTime4.count() << " s" << std::endl;
    std::cout << "Processing (MULTI) time: " << proccessTime5.count() << " s" << std::endl;
    std::cout << "2 THREADs ASYNC WAS FASTER THAN 1 ABOUT: " << (proccessTime2.count()+proccessTime3.count())-proccessTime4.count() << " s" << std::endl;
    std::cout << "2 THREADs MULTI WAS FASTER THAN 1 ABOUT: " << (proccessTime2.count()+proccessTime3.count())-proccessTime5.count() << " s" << std::endl;
    std::cout << "ASYNC (1) vs MULTI (2): " << proccessTime4.count() - proccessTime5.count() << std::endl;

    return 0;
}