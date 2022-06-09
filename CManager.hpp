#include "CImageLibrary.hpp"
#include "CFileReader.hpp"
#include "CEffectConvolution.hpp"
#include "CAnimation.hpp"
#include <map>
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
        void addImage( CFileReader &fr);
        void showImage(std::string &imageName);
        void useEffect(std::string &imageName);
        void initializeAnimation() const;
        void animationPrints(CAnimation & animation) const;
        void deleteImage(std::string &imageName);
        std::string getNameInput() ;
        std::string nameInput;
        static const std::map < std::string , CEffect * > mapEffect;
        
};  
