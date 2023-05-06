#include "CEffectNegative.hpp"

/**
 * @brief child class to CEffect
 * lighten the image
 *
 */

class CEffectLighten : public CEffect {
public:
    /**
     * @brief lighten the image by given value
     *
     * @param image
     * @return std::shared_ptr<CImage>
     */
    void applyEffect(const std::vector<std::shared_ptr<CImage>> &images) override;

};