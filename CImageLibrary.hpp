#include "CImage.hpp"
#include <vector>

class CImageLibrary
{
private:
    std::vector<CImage> library;
    std::vector<CImage>::iterator libraryIT = library.begin();
    void addImage( CImage & image );
public:
    void deleteImage ( const char index);
    
};

