#include "CEffectConvolution.hpp"

std::shared_ptr<CImage> CEffectConvolution::applyEffect(std::shared_ptr<CImage> image)
{
    std::vector<std::vector<double>> kernel = getKernel();
    std::vector<std::vector<double>> effectMatrix = image->getGrayscaleImage();
    int kernelSize = kernel.size();
    int padding = kernelSize - 1;
    int rows = image->getWidth();
    int cols = image->getHeight();
    int padded_rows = kernel.size() / 2 ;
    int padded_cols = kernel[0].size() / 2 ;
    std::cout << "halo pred forom" << std::endl;
    std::vector<std::vector<double>> padded_image(padded_rows, std::vector<double>(padded_cols, 0));
    for (int i = padding; i < rows + padding; i++) {
        for (int j = padding; j < cols + padding; j++) {
            padded_image[i][j] = effectMatrix[i - padding][j - padding];
        }
    }
    std::cout << "halo po fore" << std::endl;
    if (rows % 2 == 0) {
        for (int i = 0; i < padding; i++) {
            padded_image[padded_rows - 1][padding + i] = 0;
            padded_image[padding + i][padded_cols - 1] = 0;
        }
        padded_image[padded_rows - 1][padded_cols - 1] = 0;
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
            output_image[i - padding][j - padding] = sum;
        }
    }
    image->updateImage(output_image);
    return image;
}                 

