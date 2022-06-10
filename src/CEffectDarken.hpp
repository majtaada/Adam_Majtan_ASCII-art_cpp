#include "CEffectLighten.hpp"

class CEffectDarken : public CEffect
{
public:
    std::shared_ptr<CImage> applyEffect(std::shared_ptr<CImage> image) override;
};
