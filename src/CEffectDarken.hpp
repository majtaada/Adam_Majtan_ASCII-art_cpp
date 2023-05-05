#include "CEffectLighten.hpp"

/**
 * @brief childclass to CEffect
 * lighten the image
 *
 */

class CEffectDarken : public CEffect
{
public:
    /**
     * @brief darken the image by given value
     *
     * @param image
     * @return std::shared_ptr<CImage>
     */
    void applyEffect(const std::vector<std::shared_ptr<CImage>> &images) override;

};
