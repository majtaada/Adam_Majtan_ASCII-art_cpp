#include "CEffectShrink.hpp"
#include <vector>
/**
 * @brief child class to CEffect
 * convolutes the image
 *
 */

class CEffectConvolution : public CEffect
{
public:
    /**
     * @brief convolute the image using kernel
     *
     * @param image
     * @return std::shared_ptr<CImage>
     */
    std::shared_ptr<CImage> applyEffect(std::shared_ptr<CImage> image) override;
    static std::vector<std::vector<double>> convolve(int padding,int rows,int cols,std::vector<std::vector<double>> & kernel,std::vector<std::vector<double>>  & padded_image);
    static std::vector<std::vector<double>> expandKernel(const std::vector<std::vector<double>>& kernel);
};