#include "CImage.hpp"
#include <vector>
#include <future>
#include <thread>
#include <chrono>
#include <algorithm>

#define space "=========================="

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
    void addImage(const std::shared_ptr<CImage>& image);
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

    /**
     * @brief get the vector of CImages
     *
     * @return
     */
    std::vector<std::shared_ptr<CImage>> getAnimationSet();


private:
    /**
     * @brief pause loop, waiting for input
     *
     * @return true = resume
     * @return false = quit
     */
    bool pauseAnimation();
    /**
     * @brief deletes image from animationlibrary
     *
     * @return true if deleted
     * @return false if failed to delete
     */
    bool deleteImageFromAnimation();
    /**
     * @brief function to get input from user
     * @return the index
     */
    int indexInput() const;
    /**
     * @brief update numbers after deletion
     */
    void updateNumbers();
    /**
     * @brief print function
     */
    void printAnimationLibrary() const;
    std::vector<std::pair<int, std::shared_ptr<CImage>>> animationLibrary;
};
