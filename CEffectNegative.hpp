#include "CEffect.hpp"
#include "CImage.hpp"

class CEffectNegative : public CEffect
{
public:
    CImage CEffectNegative::applyEffect (CImage & image, int value);
};