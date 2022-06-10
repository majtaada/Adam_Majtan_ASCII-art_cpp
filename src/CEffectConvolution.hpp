#include "CEffectDarken.hpp"

class CEffectConvolution : public CEffect
{
public:
    std::shared_ptr<CImage> applyEffect(std::shared_ptr<CImage> image) override;
};