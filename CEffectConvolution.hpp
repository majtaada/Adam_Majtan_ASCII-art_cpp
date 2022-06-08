#include "CEffect.hpp"
#include "CImage.hpp"

class CEffectConvolution : public CEffect
{
public:
    CImage applyEffect(CImage & image, int value);
};