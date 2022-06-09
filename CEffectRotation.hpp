#include "CEffect.hpp"
#include <algorithm>


class CEffectRotation : public CEffect
{
public:
    CImage applyEffect(CImage & image);
    void transposeMatrix ( std::vector<std::vector<double>> imageMatrix );
    void reverseColumnsMatrix ( std::vector<std::vector<double>> imageMatrix );
};