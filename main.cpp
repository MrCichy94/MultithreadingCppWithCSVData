#include <iostream>
#include <chrono>
#include "DataReadByDefaultBuilder.hpp"


int main() {

    auto startTime = std::chrono::high_resolution_clock::now();

    auto videos = DataReadByDefaultBuilder::addDataFromFileToVector("data.csv"); //final file is "data.csv"
    /* INFO :: 40k w czasie 0,16s | 80k w czasie 0,33s (dokument .csv, format 7 kolumn)
    int liczba = 0;
    for(const auto& p : videos){
        std::cout << "Rekord numer " << liczba << ". " << p.getChannelTitle() << std::endl;
        liczba++;
    }
    */

    auto finishTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> proccessTime = finishTime - startTime;

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Processing time: " << proccessTime.count() << " s" << std::endl;

    return 0;
}
