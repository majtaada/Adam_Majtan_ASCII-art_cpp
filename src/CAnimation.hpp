#include "CImage.hpp"
#include <vector>
#include <future>
#include <chrono>

class CAnimation
{
public:
    void addImage(std::shared_ptr<CImage> image );
    void startAnimation();

    private:
        [[nodiscard]] bool pauseAnimation() const;
        std::vector <std::shared_ptr<CImage>> animationLibrary;   
};

