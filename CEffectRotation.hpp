#include "CEffect.hpp"
#include "CImage.hpp"
#include <vector>
#include <algorithm>


class CEffectRotation : public CEffect
{
public:
    CImage applyEffect(CImage & image, int value);
    void transposeMatrix ( std::vector<std::vector<double>> imageMatrix );
    void reverseColumnsMatrix ( std::vector<std::vector<double>> imageMatrix );
};