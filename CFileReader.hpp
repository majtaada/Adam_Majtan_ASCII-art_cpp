#include "CImage.hpp"
#include "CTool.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <png.h>
#pragma once


class CFileReader
{

public:
    std::string readInput() const;
    CImage readPNG (const std::string &imageName) ;
    void readAsciiTransition ( const std::string &txtName );
    void initializeAsciiTransition ( );

private:
    std::string path= "../majtaada/examples/";
    CTool * converter; 
    bool checkIfFileValid(const std::string &name) const;
    void toGrayScale ( png_structp &pngStr , png_infop &pngInfo );  
    void readDirectory( std::string fileType)const;
    int height,width,shifter;
    std::string asciiLevel;
    std::vector<std::vector<double>> imageMatrix;
    double grayscale;
};
