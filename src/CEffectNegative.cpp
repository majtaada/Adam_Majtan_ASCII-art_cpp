#include "CEffectNegative.hpp"

void CEffectNegative::applyEffect(const std::vector<std::shared_ptr<CImage>> &images) {
    for (const auto &image: images) {
        std::vector<std::vector<double>> imageMatrix = image->getGrayscaleImage();
        std::vector<std::vector<double>> effectMatrix;
        for (size_t i = 0; i < imageMatrix.size(); i++) {
            std::vector<double> v1;
            for (size_t j = 0; j < imageMatrix[i].size(); j++) {
                v1.push_back(255 - imageMatrix[i][j]);
            }
            effectMatrix.push_back(v1);
        }
        image->updateImage(effectMatrix);
    }
}