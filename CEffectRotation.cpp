#include "CEffectRotation.hpp"
#include <vector>
#include <algorithm>


CImage CEffectRotation::applyEffect ( CImage & image , int value)
{
    imageMatrix = image.getGrayscaleImage();
    transposeMatrix(imageMatrix);
    reverseColumnsMatrix(effectMatrix);
    image.updateImage(effectMatrix);
    return image;
}

void CEffectRotation::transposeMatrix ( std::vector<std::vector<double>> imageMatrix )
{    
    for (size_t i = 0; i < imageMatrix.size(); i++)
    {
        std::vector<double> v1;
        for (size_t j = 0; j < imageMatrix[i].size(); j++)
        {
            std::swap(imageMatrix[i][j],imageMatrix[j][i]);
        }
        effectMatrix.push_back(v1);
    }
}

void CEffectRotation::reverseColumnsMatrix ( std::vector<std::vector<double>> imageMatrix )
{
    for (size_t i = 0; i < imageMatrix.size(); i++)
    {
        std::vector<double> v1;
        for (size_t j = 0 , k = imageMatrix.size() - 1 ; j < k; j++ , k--)
        {
            std::swap(imageMatrix[j][i],imageMatrix[k][i]);
        }
        effectMatrix.push_back(v1);
    }
}