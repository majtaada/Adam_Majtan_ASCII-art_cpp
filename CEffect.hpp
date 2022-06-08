#include <string>
#include "CImage.hpp"

class CEffect
{
public:
    virtual CImage applyEffect ( CImage & image, int value) = 0; 
    std::vector<std::vector<double>> imageMatrix;
    std::vector<std::vector<double>> effectMatrix;
};

