#include "CEffectConvolution.hpp"

void CEffectConvolution::applyEffect(const std::vector<std::shared_ptr<CImage>> &images) {
    std::vector<std::vector<double>> kernel = getKernel();
    for (const auto &image: images) {
        std::vector<std::vector<double>> effectMatrix = image->getGrayscaleImage();
        if (kernel.size() % 2 == 0)
            kernel = expandKernel(kernel);
        int kernelSize = kernel.size();
        int padding = kernelSize / 2;
        int rows = image->getHeight();
        int cols = image->getWidth();
        std::vector<std::vector<double>> paddedImage(2 * padding + rows, std::vector<double>(2 * padding + cols, 0.0));
        for (int i = padding; i < rows + padding; i++) {
            for (int j = padding; j < cols + padding; j++) {
                paddedImage[i][j] = effectMatrix[i - padding][j - padding];
            }
        }
        std::vector<std::vector<double>> outputImage = convolve(padding, rows, cols, kernel, paddedImage);
        image->updateImage(outputImage);
    }
}

std::vector<std::vector<double>>
CEffectConvolution::convolve(int padding, int rows, int cols, std::vector<std::vector<double>> &kernel,
                             std::vector<std::vector<double>> &padded_image) {
    std::vector<std::vector<double>> output_image(rows, std::vector<double>(cols, 0));
    for (int i = padding; i < rows + padding; i++) {
        for (int j = padding; j < cols + padding; j++) {
            double sum = 0;
            for (int k = -padding; k <= padding; k++) {
                for (int l = -padding; l <= padding; l++) {
                    sum += padded_image[i + k][j + l] * kernel[k + padding][l + padding];
                }
            }
            output_image[i - padding][j - padding] = std::max(0.0, std::min(255.0, sum));
        }
    }
    return output_image;
}

std::vector<std::vector<double>> CEffectConvolution::expandKernel(const std::vector<std::vector<double>> &kernel) {
    std::vector<std::vector<double>> newKernel(kernel.size() + 1, std::vector<double>(kernel.size() + 1, 0));
    for (size_t i = 0; i < kernel.size(); i++) {
        for (size_t j = 0; j < kernel.size(); j++) {
            newKernel[i][j] = kernel[i][j];
        }
    }
    return newKernel;
}