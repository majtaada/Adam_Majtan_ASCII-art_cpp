#include "CEffectExposure.hpp"

/**
 * @brief child class to CEffectExposure
 * lighten the image
 *
 */

class CEffectLighten : public CEffectExposure {
public:
    double applyEffectToPixels(double pixelValue, int value) override;
};