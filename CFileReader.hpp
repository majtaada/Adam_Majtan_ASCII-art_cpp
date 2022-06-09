#include "CImage.hpp"
#include "CTool.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <png.h>
#include <stdexcept>
#include <filesystem>
#pragma once

#define space "=========================="

class CFileReader
{

public:
    std::string readInput() const;
    CImage* readPNG (const std::string &imageName) ;
    void readAsciiTransition ( const std::string &txtName );
    void initializeAsciiTransition ( );

private:
    void print() const;
    std::string fileFromInput , asciiLevel ,  fileName,
                path= "../majtaada/examples/";
    CTool * converter; 
    bool checkIfFileValid(const std::string &name) const;
    void toGrayScale ( png_structp &pngStr , png_infop &pngInfo );  
    void readDirectory( std::string fileType)const;
    int height,width,shifter;
    std::vector<std::vector<double>> imageMatrix;
    double grayscale;
};
