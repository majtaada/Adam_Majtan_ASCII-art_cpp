#include "CEffect.hpp"

/**
 * @brief child class to CEffect
 * turns image into negative
 *
 */

class CEffectNegative : public CEffect
{
public:
    /**
     * @brief turns image into negative
     *
     * @param image
     * @return std::shared_ptr<CImage>
     */
    std::shared_ptr<CImage> applyEffect(std::shared_ptr<CImage> image) override;
};