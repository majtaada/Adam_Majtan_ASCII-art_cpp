#include "CEffectDarken.hpp"
/**
 * @brief child class to CEffect
 * convolutes the image
 *
 */

class CEffectShrink : public CEffect
{
public:
    /**
     * @brief convolute the image
     *
     * @param image
     * @return std::shared_ptr<CImage>
     */
    std::shared_ptr<CImage> applyEffect(std::shared_ptr<CImage> image) override;
};