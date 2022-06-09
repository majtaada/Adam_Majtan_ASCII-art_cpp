#include "CImage.hpp"
#include <vector>

class CImageLibrary
{
private:
    std::vector<CImage*> library;
public:
    void addImage( CImage * image );
    void deleteImagefromLibrary ( std::string &imageName);
    void printLibrary()const;
    CImage* findImage ( std::string &imageName)const;
    
};

