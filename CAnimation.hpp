#include "CImage.hpp"
#include <vector>
#include <future>
#include <chrono>

class CAnimation
{
public:
    void addImage( CImage* image );
    void startAnimation();

    private:
        bool pauseAnimation() const;
        std::vector <CImage*> animationLibrary;   
};

