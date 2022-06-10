#include <memory>
#include "CTool.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#pragma once


class CImage
{
public:
    CImage( std::vector<std::vector<double>> &grayscaleMatrix ,std::shared_ptr<CTool> converter ,const std::string &fileName);
    void printImage () const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] std::vector<std::vector<double>> getGrayscaleImage() const;
    [[nodiscard]] std::vector<std::vector<char>> getAsciiImage() const;
    [[nodiscard]] std::string getName() const;
    void updateImage(std::vector<std::vector<double>>  &grayscaleMatrix);
private:
    std::vector<std::vector<char>> asciiImage;
    std::vector<std::vector<double>> grayscaleImage;
    std::string imageName;
    std::shared_ptr<CTool> imageConverter;
};

