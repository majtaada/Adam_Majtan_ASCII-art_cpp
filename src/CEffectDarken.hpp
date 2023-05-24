#include "CEffectLighten.hpp"

/**
 * @brief child class to CEffectExposure
 * darken the image
 *
 */
class CEffectDarken : public CEffectExposure {
public:
    double applyEffectToPixels(double pixelValue, int value) override;
};
