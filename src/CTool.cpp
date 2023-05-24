#include "CTool.hpp"

CTool::CTool(std::string &asciiTransition) {
    grayLevel = asciiTransition;
}

std::vector<std::vector<char>> CTool::convertToAscii(std::vector<std::vector<double>> &grayMatrix) const {

    int grayscale;
    int len = grayLevel.length() - 1;
    std::vector<std::vector<double>> imageMatrix = grayMatrix;
    std::vector<std::vector<char>> asciiMatrix;
    for (auto it = imageMatrix.begin(); it != imageMatrix.end(); it++) {
        std::vector<char> v1;
        for (auto it1 = it->begin(); it1 != it->end(); it1++) {
            grayscale = (len - 1) * *it1 / 255;
            v1.push_back(grayLevel[grayscale]);
        }
        asciiMatrix.push_back(v1);
    }
    return asciiMatrix;
}


std::vector<std::vector<double>> CTool::toGrayScale(png_structp &pngStr, png_infop &pngInfo) const {

    int shifter;
    std::vector<std::vector<double>> pngMatrix;
    switch (png_get_color_type(pngStr, pngInfo)) {
        case PNG_COLOR_TYPE_RGB:
            shifter = 3;
            break;
        case PNG_COLOR_TYPE_RGBA:
            shifter = 4;
            break;
        case PNG_COLOR_TYPE_GRAY:
            shifter = 1;
            break;
        case PNG_COLOR_TYPE_GA:
            shifter = 2;
            break;
        default:
            throw std::invalid_argument("Neplatny color type");
    }
    if (shifter == 1 || shifter == 2)
        return readGrayScale(pngStr, pngInfo, shifter);
    return RGBToGrayScale(pngStr, pngInfo, shifter);
}

std::vector<std::vector<double>> CTool::RGBToGrayScale(png_structp &pngStr, png_infop &pngInfo, int shifter) {
    png_bytepp rows = png_get_rows(pngStr, pngInfo);
    int width = png_get_image_width(pngStr, pngInfo);
    int height = png_get_image_height(pngStr, pngInfo);
    std::vector<std::vector<double>> pngMatrix;
    double grayscale;
    for (int row = 0; row < height; row++) {
        std::vector<double> v1;
        // Pixels in RGBA -> x4 , RGB -> x3
        for (int col = 0; col < width * shifter; col += shifter) {
            // gray = 0.2126 * red + 0.7152 * green + 0.0722 * blue
            grayscale = int(rows[row][col]) * R + int(rows[row][col + 1]) * G + int(rows[row][col + 2]) * B;
            v1.push_back(grayscale);
        }
        pngMatrix.push_back(v1);
    }
    png_destroy_read_struct(&pngStr, (png_infopp) nullptr, (png_infopp) 0);
    free(rows);
    return pngMatrix;
}

std::vector<std::vector<double>> CTool::readGrayScale(png_structp &pngStr, png_infop &pngInfo, int shifter) {
    png_bytepp rows = png_get_rows(pngStr, pngInfo);
    int width = png_get_image_width(pngStr, pngInfo);
    int height = png_get_image_height(pngStr, pngInfo);
    std::vector<std::vector<double>> pngMatrix;
    int grayscale;
    for (int row = 0; row < height; row++) {
        std::vector<double> v1;
        for (int col = 0; col < width * shifter; col += shifter) {
            grayscale = int(rows[row][col]);
            v1.push_back(grayscale);
        }
        pngMatrix.push_back(v1);
    }
    png_destroy_read_struct(&pngStr, (png_infopp) nullptr, (png_infopp) nullptr);
    free(rows);
    return pngMatrix;
}
