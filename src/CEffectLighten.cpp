#include "CEffectLighten.hpp"


double CEffectLighten::applyEffectToPixels(double pixelValue, int value) {
    if ( (pixelValue + value) > 0)
        return pixelValue - value;
    return 0;
}
