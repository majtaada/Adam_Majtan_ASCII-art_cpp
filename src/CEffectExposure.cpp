#include "CEffectExposure.hpp"


void CEffectExposure::applyEffect(const std::vector<std::shared_ptr<CImage>> &images) {
    int value = CEffect::getValue();
    if(value == -1)
        return;
    for (const auto &image: images) {
        std::vector<std::vector<double>> imageMatrix = image->getGrayscaleImage();
        std::vector<std::vector<double>> effectMatrix;
        for (size_t i = 0; i < imageMatrix.size(); i++) {
            std::vector<double> v1;
            for (size_t j = 0; j < imageMatrix[i].size(); j++) {
                v1.push_back(applyEffectToPixels(imageMatrix[i][j], value));
            }
            effectMatrix.push_back(v1);
        }
        image->updateImage(effectMatrix);
    }
}