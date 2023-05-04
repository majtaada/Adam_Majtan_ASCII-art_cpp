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
    virtual std::shared_ptr<CImage> applyEffect(std::shared_ptr<CImage> image) = 0;
    /**
     * @brief get the value for the effects (darken,lighten)
     *
     * @return unsigned int
     */
    static unsigned int getValue() ;
    static std::vector<std::vector<double>> getKernel() ;

};
