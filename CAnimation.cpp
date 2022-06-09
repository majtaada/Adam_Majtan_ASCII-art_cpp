#include "CAnimation.hpp"

void CAnimation::addImage(CImage * image)
{   
    auto aLibraryIT = animationLibrary.begin();
    if( aLibraryIT == animationLibrary.end())
        animationLibrary.push_back(image);
    else{
        if ( ((image->getWidth()) == (*aLibraryIT)->getWidth()) && ((image->getHeight()) == (*aLibraryIT)->getHeight()) )
            animationLibrary.push_back(image);
        else{
            throw std::invalid_argument("Zadaj obrazok rovnakej velkosti");
        }
    }
}
std::string GetLineFromCin() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

bool CAnimation::pauseAnimation() const
{
    std::cout << "zadaj resume" << std::endl;
    std::string input;
    while (1){
    std::cin >>  input;
    if ( input == "resume") return true;
    if (input == "quit") return false;
    }
}

// https://gist.github.com/vmrob/ff20420a20c59b5a98a1?fbclid=IwAR0gQ9c0vksmyX8YjePozDGOIW_ngdtnuy4iCiUwxYRJokJ4KQKOOGzFNeo
void CAnimation::startAnimation()
{
    int max = animationLibrary.size() -1;
    int index = 0;
    auto future = std::async(std::launch::async, GetLineFromCin);
    while (true) {
        if (future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            std::string line = future.get();
            future = std::async(std::launch::async, GetLineFromCin);
            if ( line == "p" )
                if(!pauseAnimation())
                    break;
            if (line == "q")
                break;
        }
        animationLibrary[index++]->printImage();
        std::cout << "Zadaj p pre pauznutie animacie a q pre ukoncenie" << std::endl; 
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if(index == max)
            index = 0;
    }
}