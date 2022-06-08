#include "CEffect.hpp"
#include "CImage.hpp"

class CEffectLighten : public CEffect
{
public:
    CImage applyEffect(CImage & image, int value);
};