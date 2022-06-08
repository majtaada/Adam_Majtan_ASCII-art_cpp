#include "CImageLibrary.hpp"


 void CImageLibrary::addImage ( CImage & image)
 {
     library.push_back(image);
 }

 void CImageLibrary::deleteImage ( const char index)
 {
    libraryIT = library.begin() + index;
    library.erase(libraryIT);
 }