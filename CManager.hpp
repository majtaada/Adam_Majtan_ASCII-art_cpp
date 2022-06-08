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
        void print(CImageLibrary & library) const;
        CFileReader filereader;
        char key;
        std::string imageName;
        CImageLibrary library;
        void addImage( CFileReader &fr);
        void showImage();
};  
