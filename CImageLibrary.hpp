#include "CImage.hpp"
#include <vector>

class CImageLibrary
{
private:
    std::vector<CImage> library;
    std::vector<CImage>::iterator libraryIT = library.begin();
public:
    void addImage( CImage & image );
    void deleteImage ( const char index);
    void printLibrary();
    CImage findImage ( std::string imageName);
    
};

