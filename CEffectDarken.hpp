#include "CEffect.hpp"
#include "CImage.hpp"

class CEffectDarken : public CEffect
{
public:
    CImage applyEffect(CImage & image, int value);
};
