#include "CImageLibrary.hpp"
#include "CFileHandler.hpp"
#include "CEffectConvolution.hpp"
#include "CAnimation.hpp"
#include <map>
#include <memory>
#pragma once




/**
 * @brief calls all the other classes, directing the program
 *
 */

class CManager
{
public:
    /**
     * @brief starts the program, called from main
     *
     */
    void initializeProgram();

private:
    /**
     * @brief prints some extra prints
     *
     */
    void print();
    std::string imageName;
    CFileHandler fileHandler;
    CImageLibrary library;
    /**
     * @brief checks if input is number
     *
     * @param inputString
     * @return true = number
     * @return false = not number
     */
    static bool checkIfInputNumber(const std::string &inputString) ;
    /**
     * @brief CFileHandler is called
     *
     * @param fr
     */
    void addImage(CFileHandler &fr);
    /**
     * @brief finds and shows image
     *
     * @param name
     */
    void showImage(std::string &name);
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
    void initializeAnimation() const;
    /**
     * @brief prints some extra prints for animation
     *
     * @param animation
     */
    void animationPrints(CAnimation &animation) const;
    /**
     * @brief finds image and deletes it after
     *
     */
    void deleteImage();
    /**
     * @brief prints basic menu
     *
     */
    static void printMenu() ;
    /**
     * @brief checks if there are images in library
     *
     * @return true = zero
     * @return false = !zero
     */
    bool zeroImages() const;
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
    std::string getNameInput();
    std::string nameInput;
    static const std::map<std::string, std::shared_ptr<CEffect>> mapEffect;

    void saveImage(std::string &name);

    int getNumberOfImages();

    void setOfImages(int numberOfImages);

    static void printImagesSet(const std::vector<std::shared_ptr<CImage>> &image);

    void printAnimationSet();
};
