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

/**
 * @brief class to manipulate with files, CTool and CImage is called from this
 * 
 */

class CFileReader
{

public:
    /**
     * @brief get input from user, checks if valid
     * 
     * @return std::string 
     */
    std::string readInput() const;
    /**
     * @brief opens a png file, store it in vector matrix using CTool's converter
     * 
     * @param imageName name of the .png file
     * @return std::shared_ptr<CImage> 
     */
    std::shared_ptr<CImage> readPNG (const std::string &imageName) ;
    /**
     * @brief read ascii transition from .txt file
     * 
     */
    void initializeAsciiTransition ( );

private:
    /**
     * @brief checks if file is valid 
     * 
     * @param name 
     * @return true = valid
     * @return false = invalid
     */
    bool checkIfFileValid(const std::string &name) const;
    /**
     * @brief prints directory where examples are stored
     * 
     * @param fileType 
     */
    void readDirectory( std::string fileType)const;
    std::vector<std::vector<double>> imageMatrix;
    std::string asciiLevel , path= "../majtaada/examples/";
    std::shared_ptr<CTool> converter; 
};
