#include <vector>
#include "CTool.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#pragma once


class CImage
{
public:
    CImage( std::vector<std::vector<double>> &grayscaleMatrix ,CTool * converter ,const std::string &fileName);
    void printImage () const;
    int getWidth() const;
    int getHeight() const;
    std::string getGraylevel() const;
    std::vector<std::vector<double>> getGrayscaleImage() const;
    std::vector<std::vector<char>> getAsciiImage() const;
    std::string getName() const;
    void updateImage(std::vector<std::vector<double>>  &grayscaleMatrix);
private:
    std::vector<std::vector<char>> asciiImage;
    std::vector<std::vector<double>> grayscaleImage;
    std::string imageName;
    CTool * imageConverter;
};

