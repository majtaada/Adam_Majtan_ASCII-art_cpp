#include "CEffectConvolution.hpp"

std::shared_ptr<CImage> CEffectConvolution::applyEffect(std::shared_ptr<CImage> image)
{
    std::vector<std::vector<double>> kernel = getKernel();
    std::vector<std::vector<double>> effectMatrix = image->getGrayscaleImage();
    int kernelSize = kernel.size();
    int padding = kernelSize / 2;
    int rows = image->getHeight();
    int cols = image->getWidth();
    std::vector<std::vector<double>> padded_image(2*padding + rows, std::vector<double>(2*padding + cols, 0.0));
    for (int i = padding; i < rows + padding; i++) {
        for (int j = padding; j < cols + padding; j++) {
            std::cout << i <<","<<j << std::endl;
            padded_image[i][j] = effectMatrix[i - padding][j - padding];
        }
    }
    std::vector<std::vector<double>> output_image(rows, std::vector<double>(cols, 0));
    for (int i = padding; i < rows + padding; i++) {
        for (int j = padding; j < cols + padding; j++) {
            double sum = 0;
            for (int k = -padding; k <= padding; k++) {
                for (int l = -padding; l <= padding; l++) {
                    sum += padded_image[i + k][j + l] * kernel[k + padding][l + padding];
                }
            }
            output_image[i - padding][j - padding] = std::max(0.0,std::min(255.0,sum));
        }
    }
    image->updateImage(output_image);
    return image;
}                 

