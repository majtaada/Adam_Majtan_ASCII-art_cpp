#include "CEffectShrink.hpp"
#include <vector>
/**
 * @brief child class to CEffect
 * convolve the image
 *
 */

class CEffectConvolution : public CEffect
{
public:
    /**
     * @brief convolve the image using kernel
     *
     * @param image
     * @return std::shared_ptr<CImage>
     */
    void applyEffect(const std::vector<std::shared_ptr<CImage>> &images) override;
    /**
     * @brief make the convolution
     *
     * @param padding
     * @param rows
     * @param cols
     * @param kernel
     * @param padded_image
     * @return
     */
    static std::vector<std::vector<double>> convolve(int padding,int rows,int cols,std::vector<std::vector<double>> & kernel,std::vector<std::vector<double>>  & padded_image);

    /**
     * @brief if the kernel is even size add zero padding
     *
     * @param kernel
     * @return
     */
    static std::vector<std::vector<double>> expandKernel(const std::vector<std::vector<double>>& kernel);

};