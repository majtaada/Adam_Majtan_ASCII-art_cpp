#include "CImageLibrary.hpp"

void CImageLibrary::addImage ( std::shared_ptr<CImage> &image )
{
    library.push_back(std::make_pair(library.size()+1,image));
}


bool CImageLibrary::deleteImageFromLibrary ( std::string &imageName ) 
{
    int deleted = 0;
    for( auto libraryIT = library.begin() ;  libraryIT != library.end() ; libraryIT++)
        if( (*(*libraryIT).second).getName() == imageName){
            library.erase(libraryIT);
            updateNumbers();
            return true;
        }
    std::cout << "Takyto image nemame :)" << std::endl;    
    return false;
}

void CImageLibrary::updateNumbers() 
{   
    if(getLibrarySize())
        for(size_t i = 0 ; i <= getLibrarySize() - 1 ; i++ )
            library[i].first = i + 1;
        
}

bool CImageLibrary::deleteImageFromLibrary ( int index ) 
{
    int deleted = 0;
    for( auto libraryIT = library.begin() ;  libraryIT != library.end() ; libraryIT++){
        if( (*libraryIT).first == index ){
            library.erase(libraryIT);
            updateNumbers();
            return true;
        }
    }
    std::cout << "Takyto image nemame :)" << std::endl;    
    return false;
}

std::shared_ptr<CImage> CImageLibrary::findImage ( std::string &imageName ) const
{
    for(const auto & libraryIT : library)
        if( (*libraryIT.second).getName() == imageName)
            return libraryIT.second;
    return nullptr;
}

std::shared_ptr<CImage> CImageLibrary::findImage ( int imageNumber ) const
{
    for(const auto & libraryIT : library)
        if( libraryIT.first == imageNumber)
            return libraryIT.second;
    return nullptr;
}

int CImageLibrary::getLibrarySize() const 
{
    return this->library.size();
}

void CImageLibrary::printLibrary() const
{   
    for(const auto & libraryIT : library){
        std::cout << "[" << (libraryIT.first) << "]" << " " << (*libraryIT.second).getName() << std::endl;
    }
}

