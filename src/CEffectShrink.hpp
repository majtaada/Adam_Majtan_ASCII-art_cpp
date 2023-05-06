#include "CEffectDarken.hpp"

/**
 * @brief child class to CEffect
 * shrinks the image
 *
 */

class CEffectShrink : public CEffect {
public:
    /**
     * @brief shrinks the image
     *
     * @param image
     * @return std::shared_ptr<CImage>
     */
    void applyEffect(const std::vector<std::shared_ptr<CImage>> &images) override;

};