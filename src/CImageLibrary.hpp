#include "CImage.hpp"
#include <vector>
#include <memory>

class CImageLibrary
{
private:
    std::vector<std::pair<int,std::shared_ptr<CImage>>> library;
public:
    void addImage( std::shared_ptr<CImage> & image );
    bool deleteImageFromLibrary ( std::string &imageName);
    bool deleteImageFromLibrary ( int index );
    void printLibrary()const;
    std::shared_ptr<CImage> findImage ( std::string &imageName)const;
    std::shared_ptr<CImage> findImage ( int index )const;

};

