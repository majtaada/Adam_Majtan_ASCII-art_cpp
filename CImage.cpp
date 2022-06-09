#include "CImage.hpp"




CImage::CImage ( std::vector<std::vector<double>>  &grayscaleMatrix , CTool  * converter ,const std::string &fileName)
{
    asciiImage = converter->convertToAscii(grayscaleMatrix);
    grayscaleImage = grayscaleMatrix;  
    imageName = fileName;
    imageConverter = converter;
}

int CImage::getHeight( ) const
{
    return this->asciiImage.size();
}

int CImage::getWidth() const
{
    return this->asciiImage[0].size();
}


std::string CImage::getName() const
{
    return this->imageName;
}

std::vector<std::vector<double>> CImage::getGrayscaleImage() const
{
    return this->grayscaleImage;
}

std::vector<std::vector<char>> CImage::getAsciiImage() const
{
    return this->asciiImage;
}


void CImage::updateImage(std::vector<std::vector<double>>  &grayscaleMatrix) 
{
    grayscaleImage= grayscaleMatrix;
    asciiImage = imageConverter->convertToAscii(grayscaleImage);
}

void CImage::printImage () const
{
    system("clear");
    for (int i = 0; i < getHeight(); i++)
    {
        for (int j = 0; j < getWidth(); j++)
        {
            std::cout << asciiImage[i][j] << " ";
        }
        std::cout << "\n";
    }
}