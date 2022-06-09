#include "CImageLibrary.hpp"

void CImageLibrary::addImage ( CImage * image)
{
    library.push_back(image);
}

void CImageLibrary::deleteImagefromLibrary ( std::string &imageName ) 
{
    for( auto libraryIT = library.begin() ;  libraryIT != library.end() ; libraryIT++)
        if((**libraryIT).getName() == imageName){
            library.erase(libraryIT);
            break;}
    throw std::invalid_argument("Takyto image nemame :)");
}

CImage* CImageLibrary::findImage ( std::string &imageName ) const
{
    for( auto libraryIT = library.begin() ;  libraryIT != library.end() ; libraryIT++)
        if( (**libraryIT).getName() == imageName)
            return (*libraryIT);
    throw std::invalid_argument("Takyto image nemame :)");
}

void CImageLibrary::printLibrary() const
{
    for( auto libraryIT = library.begin() ;  libraryIT != library.end() ; libraryIT++)
        std::cout << (**libraryIT).getName() << std::endl;
}

