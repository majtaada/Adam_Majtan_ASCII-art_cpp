#include "CImageLibrary.hpp"

void CImageLibrary::addImage ( std::shared_ptr<CImage> &image )
{
    library.push_back(image);
}


void CImageLibrary::deleteImageFromLibrary ( std::string &imageName ) 
{
    auto libraryIT = library.begin();
    int deleted = 0;
    for(  ;  libraryIT != library.end() ; libraryIT++)
        if((**libraryIT).getName() == imageName){
            library.erase(libraryIT);
            deleted++;
            break;
        }
    if (!deleted)
        throw std::invalid_argument("Takyto image nemame :)");
}

std::shared_ptr<CImage> CImageLibrary::findImage ( std::string &imageName ) const
{
    for(const auto & libraryIT : library)
        if( (*libraryIT).getName() == imageName)
            return libraryIT;
    throw std::invalid_argument("Takyto image nemame :)");
}


void CImageLibrary::printLibrary() const
{
    for(const auto & libraryIT : library)
        std::cout << (*libraryIT).getName() << std::endl;
}

