#include "CEffectNegative.hpp"
/**
 * @brief child class to CEffect
 * lighten the image
 * 
 */

class CEffectLighten : public CEffect
{
public:
    /**
     * @brief lighten the image by given value
     * 
     * @param image 
     * @return std::shared_ptr<CImage> 
     */
    std::shared_ptr<CImage>  applyEffect(std::shared_ptr<CImage> image) override;
};