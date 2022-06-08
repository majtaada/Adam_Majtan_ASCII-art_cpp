#include "CFileReader.hpp"
#include "CTool.hpp"
#include "CImage.hpp"
#include <string>
#include <png.h>

int main(void)
{   
    CFileReader a;
    a.initializeAsciiTransition();
    while(1){
    std::string fileName=a.readInput();
    CImage image =a.readPNG(fileName);
    image.printImage();
    }    
    return 0;
}
