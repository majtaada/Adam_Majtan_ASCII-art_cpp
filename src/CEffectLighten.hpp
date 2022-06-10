#include "CEffectNegative.hpp"

class CEffectLighten : public CEffect
{
public:
    std::shared_ptr<CImage>  applyEffect(std::shared_ptr<CImage> image) override;
};