#include "CEffectDarken.hpp"


double CEffectDarken::applyEffectToPixels(double pixelValue, int value) {
    if ((pixelValue + value) <= 255 || (pixelValue + value) > 0)
       return pixelValue + value;
    return 255;
}
