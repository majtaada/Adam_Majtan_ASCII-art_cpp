#include "CImage.hpp"
#include "CTool.hpp"
#include "CImageLibrary.hpp"
#include "CFileReader.hpp"
#include "CEffect.hpp"

class CManager
{
    public:
        void initializeProgram();
    private:
        CFileReader filereader;
        char key;
        std::string imageName;
        CImageLibrary library;
        void addImage( );
        void showImage();
};  
