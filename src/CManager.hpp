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
        void initializeProgram();
    private:
        void print() ;
        CFileReader filereader;
        char key;
        std::string imageName;
        CImageLibrary library;
        bool checkIfInputNumber(const std::string& inputString) const;
        void addImage( CFileReader &fr);
        void showImage(std::string &name);
        void useEffect(std::string &string);
        void initializeAnimation() const;
        void animationPrints(CAnimation & animation) const;
        void deleteImage() ;
        void printMenu() const;
        bool zeroImages() const;
        std::shared_ptr<CImage> handleInput(std::string &name) const;
        std::string getNameInput() ;
        std::string nameInput;
        static const std::map < std::string , std::shared_ptr<CEffect>> mapEffect;
        
};  
