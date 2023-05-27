#include <vector>
#include <string>
#include <png.h>
#include <iostream>

#pragma once

#define R 0.2126
#define B 0.0722
#define G 0.7152

/**
 * @brief class to convert matrixes
 *
 */

class CTool {
public:
    /**
     * @brief Construct a new CTool , given ascii transition is stored
     *
     * @param asciiTransition
     */
    explicit CTool(std::string &asciiTransition);

    /**
     * @brief get matrix in grayscale and converts it to adequate ascii symbol
     *
     * @param grayMatrix
     * @return std::vector<std::vector<char>>
     */
    std::vector<std::vector<char>> convertToAscii(std::vector<std::vector<double>> &grayMatrix) const;

    /**
     * @brief decide what the colortype of png is and then calls adequate method
     *
     * @param pngStr
     * @param pngInfo
     * @return std::vector<std::vector<double>>
     */
    std::vector<std::vector<double>> toGrayScale(png_structp &pngStr, png_infop &pngInfo) const;

private:
    std::string grayLevel;

    /**
     * @brief read and store grayscale values into vector matrix
     *
     * @param pngStr
     * @param pngInfo
     * @param shifter
     * @return std::vector<std::vector<double>>
     */
    static std::vector<std::vector<double>> readGrayScale(png_structp &pngStr, png_infop &pngInfo, int shifter);

    /**
     * @brief read rgb values, then store it as grayscale value into vector matrix
     *
     * @param pngStr
     * @param pngInfo
     * @param shifter
     * @return std::vector<std::vector<double>>
     */
    static std::vector<std::vector<double>> RGBToGrayScale(png_structp &pngStr, png_infop &pngInfo, int shifter);
};
