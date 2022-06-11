#include "CImageLibrary.hpp"
#include "CFileReader.hpp"
#include "CEffectConvolution.hpp"
#include "CAnimation.hpp"
#include <map>
#include <memory>
#pragma once

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
        void print() ;
        CFileReader filereader;
        char key;
        std::string imageName;
        CImageLibrary library;
        /**
         * @brief checks if input is number
         * 
         * @param inputString 
         * @return true = number
         * @return false = not number
         */
        bool checkIfInputNumber(const std::string& inputString) const;
        /**
         * @brief CFileReader is called
         * 
         * @param fr 
         */
        void addImage( CFileReader &fr);
        /**
         * @brief finds and shows image
         * 
         * @param name 
         */
        void showImage(std::string &name);
        /**
         * @brief finds image and use effect
         * 
         * @param string 
         */
        void useEffect(std::string &string);
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
        void animationPrints(CAnimation & animation) const;
        /**
         * @brief finds image and deletes it after
         * 
         */
        void deleteImage() ;
        /**
         * @brief prints basic menu
         * 
         */
        void printMenu() const;
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
        std::string getNameInput() ;
        std::string nameInput;
        static const std::map < std::string , std::shared_ptr<CEffect>> mapEffect;
        
};  
