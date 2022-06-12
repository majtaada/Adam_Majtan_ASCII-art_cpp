#include "CImage.hpp"
#include <vector>
#include <memory>

/**
 * @brief class to store CImage
 *
 */

class CImageLibrary
{
private:
    std::vector<std::pair<int, std::shared_ptr<CImage>>> library;

public:
    /**
     * @brief add image and his number to vector
     *
     * @param image
     */
    void addImage(std::shared_ptr<CImage> &image);
    /**
     * @brief deletes image from library
     *
     * @param imageName
     * @return true deleted
     * @return false not in library
     */
    bool deleteImageFromLibrary(std::string &imageName);
    bool deleteImageFromLibrary(int index);
    /**
     * @brief prints library
     *
     */
    void printLibrary() const;
    /**
     * @brief get the size of library
     *
     * @return int
     */
    int getLibrarySize() const;
    /**
     * @brief updates numbers of images after deletion , so they start with 1
     *
     */
    void updateNumbers();
    /**
     * @brief finds image by name or number and returns pointer
     *
     * @param imageName
     * @return std::shared_ptr<CImage>
     */
    std::shared_ptr<CImage> findImage(std::string &imageName) const;
    std::shared_ptr<CImage> findImage(int index) const;
};
