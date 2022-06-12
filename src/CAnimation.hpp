#include "CImage.hpp"
#include <vector>
#include <future>
#include <chrono>

/**
 * @brief controls run of animation
 *
 */

class CAnimation
{
public:
    /**
     * @brief add image to animation library
     *          if the width and height is the same as in the library
     *
     * @param image
     */
    void addImage(std::shared_ptr<CImage> image);
    /**
     * @brief start while loop until pause or resume is given from input
     *
     */
    void startAnimation();
    /**
     * @brief Get the animation library size
     *
     * @return int
     */
    int getAnimationSize() const;

private:
    /**
     * @brief pause loop, waiting for input
     *
     * @return true = resume
     * @return false = quit
     */
    bool pauseAnimation() const;
    std::vector<std::pair<int, std::shared_ptr<CImage>>> animationLibrary;
};
