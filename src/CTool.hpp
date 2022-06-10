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
    explicit CTool ( std::string &asciiTransition );
    std::vector<std::vector<char>> convertToAscii ( std::vector<std::vector<double>> &grayMatrix) const ;
    std::vector<std::vector<double>> toGrayScale ( png_structp &pngStr , png_infop &pngInfo ) const ;
private:    
    std::string grayLevel;
    std::vector<std::vector<double>> readGrayScale(png_structp &pngStr , png_infop &pngInfo , int shifter) const;
    std::vector<std::vector<double>> RGBToGrayScale(png_structp &pngStr , png_infop &pngInfo , int shifter) const;
};