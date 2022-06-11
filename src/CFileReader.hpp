#include "CImage.hpp"
#include "CTool.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <png.h>
#include <filesystem>
#pragma once

#define space "=========================="
#define bigSpace "=============================================================================="

class CFileReader
{

public:
    [[nodiscard]] std::string readInput() const;
    std::shared_ptr<CImage> readPNG (const std::string &imageName) ;
    void initializeAsciiTransition ( );

private:
    std::string asciiLevel , path= "../majtaada/examples/";
    std::shared_ptr<CTool> converter; 
    [[nodiscard]] bool checkIfFileValid(const std::string &name) const;
    void readDirectory( std::string fileType)const;
    std::vector<std::vector<double>> imageMatrix;
};
