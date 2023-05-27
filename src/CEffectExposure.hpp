#include "CEffectNegative.hpp"
/**
 * @brief child class to CEffect
 *  parent class to CEffectLighten and CEffectDarken
 */
class CEffectExposure : public CEffect {
public:
    /**
     * @brief darken/lighten the image by given value
     *
     * @param image
     * @return std::shared_ptr<CImage>
     */
    void applyEffect(const std::vector<std::shared_ptr<CImage>> &images) override;
    /**
     * @brief
     *
     * @param pixelValue
     * @param value
     * @return
     */
    virtual double applyEffectToPixels(double pixelValue, int value) = 0;
};


