#include <vector>
#include <string>
#include <png.h>
#include <iostream>
#pragma once

#define R 0.2126
#define B 0.0722
#define G 0.7152

class CTool
{
public:
    CTool ( std::string &asciiTransition );
    std::vector<std::vector<char>> convertToAscii ( std::vector<std::vector<double>> &imageMatrix) ;
    std::vector<std::vector<char>> asciiMatrix;
    std::vector<std::vector<double>> toGrayScale ( png_structp &pngStr , png_infop &pngInfo ) ;
private:    
    std::string grayLevel;
};
