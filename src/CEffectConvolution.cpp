#include "CEffectConvolution.hpp"
#include <vector>

std::shared_ptr<CImage> CEffectConvolution::applyEffect (std::shared_ptr<CImage> image  )
{   
    std::vector<std::vector<double>> imageMatrix = image->getGrayscaleImage();
    std::vector<std::vector<double>> effectMatrix;
    double average;
    for (size_t i = 1; imageMatrix.size() -1 - i  > 3; i+=3)
    {
        std::vector<double> v1;
        for (size_t j = 1; imageMatrix[i].size() -1 - j > 3; j+=3)
        {   
            average = 0;
            for (size_t k = i-1; k < i+2 ; k++)
            {
                average +=imageMatrix[k][j-1]+imageMatrix[k][j]+imageMatrix[k][j+1];
            }

            v1.push_back(average/9);
        }
        effectMatrix.push_back(v1);
    }
    image->updateImage(effectMatrix);
    return image;
}