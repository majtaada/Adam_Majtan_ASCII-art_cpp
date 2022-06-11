#include "CImage.hpp"
#include <vector>
#include <future>
#include <chrono>

class CAnimation
{
public:
    void addImage(std::shared_ptr<CImage> image );
    void startAnimation();
    int getAnimationSize() const;
    private:
    
        [[nodiscard]] bool pauseAnimation() const;
        std::vector <std::pair<int,std::shared_ptr<CImage>>> animationLibrary;   
};

