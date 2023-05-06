#include <memory>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "CTool.hpp"

#pragma once

/**
 * @brief image object
 *
 */

class CImage {
public:
    /**
     * @brief Construct a new CImage object
     *
     * @param grayscaleMatrix
     * @param converter
     * @param fileName
     */
    explicit CImage(std::vector<std::vector<double>> &grayscaleMatrix, const std::shared_ptr<CTool> &converter,
                    const std::string &fileName);

    /**
     * @brief clears a screen and prints a image
     *
     */
    void printImage() const;

    /**
     * @brief get the width of image
     *
     * @return int
     */
    int getWidth() const;

    /**
     * @brief get the height of image
     *
     * @return int
     */
    int getHeight() const;

    /**
     * @brief Get the Grayscale matrix of object
     *
     * @return std::vector<std::vector<double>>
     */
    std::vector<std::vector<double>> getGrayscaleImage() const;

    /**
     * @brief Get the Ascii matrix of object
     *
     * @return std::vector<std::vector<char>>
     */
    std::vector<std::vector<char>> getAsciiImage() const;

    /**
     * @brief Get the name object
     *
     * @return std::string
     */
    std::string getName() const;

    /**
     * @brief updates image after effect
     *
     * @param grayscaleMatrix
     */
    void updateImage(std::vector<std::vector<double>> &grayscaleMatrix);

private:
    std::vector<std::vector<char>> asciiImage;
    std::vector<std::vector<double>> grayscaleImage;
    std::vector<std::vector<double>> kernel;
    std::string imageName;
    std::shared_ptr<CTool> imageConverter;
};
