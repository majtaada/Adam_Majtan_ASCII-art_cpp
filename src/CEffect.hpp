#include <string>
#include <memory>
#include "CImage.hpp"

class CEffect
{
public:
    virtual std::shared_ptr<CImage> applyEffect ( std::shared_ptr<CImage> image) = 0; 
    int getValue ( ) ;
    int value = 0;
};

