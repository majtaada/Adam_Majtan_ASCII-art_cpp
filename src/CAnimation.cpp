#include "CAnimation.hpp"

void CAnimation::addImage(std::shared_ptr<CImage> image)
{   
    auto aLibraryIT = animationLibrary.begin();
    if( aLibraryIT == animationLibrary.end())
        animationLibrary.push_back(std::make_pair(animationLibrary.size(),image));
    else{
        if ( ((image->getWidth()) == ((*aLibraryIT).second)->getWidth()) && ((image->getHeight()) == ((*aLibraryIT).second)->getHeight()) )
            animationLibrary.push_back(std::make_pair(animationLibrary.size(),image));
        else
            std::cout << "Zadaj obrazok rovnakej velkosti" << std::endl;
    }
}
std::string GetLineFromCin() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

bool CAnimation::pauseAnimation() const
{
    std::cout << "Zadaj resume pre znovuspustenie, quit pre ukoncenie" << std::endl;
    std::string input;
    while (true){
    std::cin >>  input;
    if ( input == "resume") return true;
    if (input == "quit") return false;
    }
}

int CAnimation::getAnimationSize()const
{
    return this->animationLibrary.size();
}

// https://gist.github.com/vmrob/ff20420a20c59b5a98a1?fbclid=IwAR0gQ9c0vksmyX8YjePozDGOIW_ngdtnuy4iCiUwxYRJokJ4KQKOOGzFNeo
void CAnimation::startAnimation()
{
    int max = animationLibrary.size() ;
    int index = 0;
    auto future = std::async(std::launch::async, GetLineFromCin);
    while (true) {
        if (future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            std::string line = future.get();
            future = std::async(std::launch::async, GetLineFromCin);
            if ( line == "pause" )
                if(!pauseAnimation())
                    break;
            if (line == "quit")
                break;
        }
        animationLibrary[index++].second->printImage();
        std::cout << "Zadaj pause pre pauznutie animacie a quit pre ukoncenie" << std::endl; 
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if(index == max)
            index = 0;
    }
}