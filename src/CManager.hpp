#include "CImageLibrary.hpp"
#include "CFileHandler.hpp"
#include "CEffectConvolution.hpp"
#include "CAnimation.hpp"
#include <map>
#include <memory>


/**
 * @brief calls all the other classes, directing the program
 *
 */

class CManager {
public:
    /**
     * @brief starts the program, called from main
     *
     */
    void initializeProgram();

    friend class CTests;

private:
    /**
     * @brief prints some extra prints
     *
     */
    void print();


    /**
     * @brief checks if input is number
     *
     * @param inputString
     * @return true = number
     * @return false = not number
     */
    static bool checkIfInputNumber(const std::string &inputString);

    /**
     * @brief CFileHandler is called
     *
     * @param fr
     */
    bool addImage(CFileHandler &fr);

    /**
     * @brief finds and shows image
     *
     * @param name
     */
    void showImage(std::string &name);

    /**
     * @brief helper function to clean input
     */
    static void clearInput();

    /**
     * @brief use effect on set of images
     *
     * @param string
     */
    static void useEffect(const std::vector<std::shared_ptr<CImage>> &images);

    /**
     * @brief CAnimation is called
     *
     */
    void initializeAnimation();

    /**
     * @brief prints some extra prints for animation
     *
     * @param animation
     */
    void animationPrints(CAnimation &animation);

    /**
     * @brief finds image and deletes it after
     *
     */
    void deleteImage();

    /**
     * @brief prints basic menu
     *
     */
    static void printMenu();

    /**
     * @brief checks if there are images in library
     *
     * @return true = zero
     * @return false = !zero
     */
    [[nodiscard]] bool zeroImages() const;

    /**
     * @brief decide if input it string or number
     *        then calls adequate method
     *
     * @param name
     * @return std::shared_ptr<CImage>
     */
    std::shared_ptr<CImage> handleInput(std::string &name) const;

    /**
     * @brief gets input from user
     *
     * @return std::string
     */
    std::string getNameInput(bool effect);

    /**
     * @brief save the image
     *
     * @param name
     */
    void saveImage(std::string &name);

    /**
     * @brief get number of images to use effect on
     */
    unsigned int getNumberOfImages();

    /**
     * @brief create vector of CImages for effect
     */
    void setOfImages(unsigned int numberOfImages);

    /**
     * @brief prints the vector of CImages
     */
    void printImagesSet() const;

    std::string imageName;
    CFileHandler fileHandler;
    CImageLibrary library;
    std::string nameInput;
    std::vector<std::shared_ptr<CImage>> images;
    static const std::map<std::string, std::shared_ptr<CEffect>> mapEffect;
};
