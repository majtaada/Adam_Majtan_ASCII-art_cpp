#include "CImage.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <png.h>
#include <filesystem>
#include <map>

#pragma once
#define bigSpace "=============================================================================================="
#define space "=========================="
#define FORMAT_LEN 4

/**
 * @brief class to manipulate with files, CTool and CImage is called from this
 *
 */

class CFileHandler
{

public:
    /**
     * @brief get input from user, checks if valid
     *
     * @return std::string
     */
    std::string readInput() ;
    /**
     * @brief opens a png file, store it in vector matrix using CTool's converter
     *
     * @param imageName name of the .png file
     * @return std::shared_ptr<CImage>
     */
    std::shared_ptr<CImage> readPNG(const std::string &imageName);
    /**
     * @brief read ascii transition from .txt file
     *
     */
    bool initializeAsciiTransition();
    /**
     * @brief read kernel from .txt file
     *
     */
    std::vector<std::vector<double>> readKernel();
    /**
     * @brief function to save the image
     */
    void saveImage( const std::shared_ptr<CImage>&);

private:
    /**
     * @brief checks if file is valid
     *
     * @param name
     * @return true = valid
     * @return false = invalid
     */
    [[nodiscard]] static bool checkIfFileValid(const std::string &name);
    /**
     * @brief prints directory where examples are stored
     *
     * @param fileType
     */
    void readDirectory(const std::string& fileType);
    /**
     * @brief try to read from txt file, determine if file is correct
     *
     *
     * @param fileName
     * @param ascii if it is ascii file then true, if kernel file false
     * @return true if file is ok, false otherwise
     */
    bool readTxtFile(std::string & fileName,bool ascii);
    /**
     * @brief try to read from txt file, determine if file is correct, store it in kernel
     *
     * @param txtFile
     * @param line
     * @return true if file is ok, false otherwise
     */
    bool handleKernelFile(std::ifstream & txtFile);
    static int tryNumber(std::string fileNum);
    /**
     * @brief helper method to print if file is invalid
     *
     * @param mess
     */
    static void printInvalid(const std::string & mess);

    /**
     * @brief finds corresponding name of file to number
     *
     * @return std::string
     */
    std::string getInputNumber();
    /**
     * @brief utility function for sort
     *
     * @param a
     * @param b
     * @return
     */
    std::vector<std::vector<double>> imageMatrix;
    std::string asciiLevel, path = "../majtaada/examples/";
    std::shared_ptr<CTool> converter;
    std::vector<std::vector<double>> kernel;
    std::map<int,std::string> directoryMap;
    friend class CTests;
};
