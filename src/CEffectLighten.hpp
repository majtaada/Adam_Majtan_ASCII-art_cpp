#include "CEffectExposure.hpp"

/**
 * @brief child class to CEffect
 * lighten the image
 *
 */

class CEffectLighten : public CEffectExposure {
public:
    double applyEffectToPixels(double pixelValue, int value) override;
};