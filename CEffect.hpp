#include <string>
#include "CImage.hpp"

class CEffect
{
public:
    virtual CImage* applyEffect ( CImage * image) = 0; 
    int getValue ( ) ;
    int value;
};

