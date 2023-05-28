#include <string>
#include <memory>
#include <limits>
#include <vector>
#include "CImage.hpp"
#include "CFileHandler.hpp"

/**
 * @brief parent class to all effects
 *
 */
class CEffect
{
public:
    /**
     * @brief apply effect on given image, then update image and return it
     *
     *
     * @param image
     * @return std::shared_ptr<CImage>
     */
    virtual void applyEffect(const std::vector<std::shared_ptr<CImage>> &images) = 0;
    /**
     * @brief get the value for the effects (darken,lighten)
     *
     * @return unsigned int
     */
    static int getValue() ;
    /**
     * @brief get the kernel for convolution
     *
     * @return the kernel
     */
    static std::vector<std::vector<double>> getKernel() ;

};
