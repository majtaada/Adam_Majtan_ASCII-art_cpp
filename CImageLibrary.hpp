#include "CImage.hpp"
#include <vector>

class CImageLibrary
{
private:
    std::vector<CImage*> library;
public:
    ~CImageLibrary();
    void addImage( CImage * image );
    void deleteImageFromLibrary ( std::string &imageName);
    void printLibrary()const;
    CImage* findImage ( std::string &imageName)const;
    
};

