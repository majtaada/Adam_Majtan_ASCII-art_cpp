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

CImage CImageLibrary::findImage ( std::string imageName )
{
    for( libraryIT = library.begin() ;  libraryIT != library.end() ; libraryIT++)
        if( (*libraryIT).getName() == imageName)
            return (*libraryIT);
    throw std::invalid_argument("Takyto image nemame :)");
}

void CImageLibrary::printLibrary() 
{
    for( libraryIT = library.begin() ;  libraryIT != library.end() ; libraryIT++)
        std::cout << (*libraryIT).getName() << std::endl;
}