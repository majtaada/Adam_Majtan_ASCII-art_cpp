#include "CImage.hpp"
#include <vector>
#include <memory>

class CImageLibrary
{
private:
    std::vector<std::shared_ptr<CImage>> library;
public:
    void addImage( std::shared_ptr<CImage> & image );
    void deleteImageFromLibrary ( std::string &imageName);
    void printLibrary()const;
    std::shared_ptr<CImage> findImage ( std::string &imageName)const;
    
};

