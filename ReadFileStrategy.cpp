#pragma once

#include <vector>

#include "Video.hpp"

class ReadFileStrategy{

public:

    virtual std::vector<Video> addDataFromFileToVector(const std::string& fileInput) = 0;

};