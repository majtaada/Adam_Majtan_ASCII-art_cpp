#include "CImageLibrary.hpp"

void CImageLibrary::addImage ( CImage * image)
{
    library.push_back(image);
}

CImageLibrary::~CImageLibrary()
{
    for(  auto libraryIT = library.begin();   libraryIT != library.end() ; libraryIT++)
        delete ( *libraryIT);
}

void CImageLibrary::deleteImageFromLibrary ( std::string &imageName ) 
{
    auto libraryIT = library.begin();
    int deleted = 0;
    for(  ;  libraryIT != library.end() ; libraryIT++)
        if((**libraryIT).getName() == imageName){
            delete ( *libraryIT);
            library.erase(libraryIT);
            deleted++;
            break;
        }
    if (!deleted)
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

