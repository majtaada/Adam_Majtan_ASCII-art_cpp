#include <string>
#include "CImage.hpp"

class CEffect
{
public:
    virtual CImage applyEffect ( CImage & image) = 0; 
    int getValue ( ) ;
    int value;
    std::vector<std::vector<double>> imageMatrix;
    std::vector<std::vector<double>> effectMatrix;
};

