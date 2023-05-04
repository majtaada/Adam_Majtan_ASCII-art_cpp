#include "CAnimation.hpp"

void CAnimation::addImage(const std::shared_ptr<CImage>& image)
{
    auto aLibraryIT = animationLibrary.begin();
    if (aLibraryIT == animationLibrary.end())
        animationLibrary.emplace_back(animationLibrary.size()+1, image);
    else
    {
        if (((image->getWidth()) == ((*aLibraryIT).second)->getWidth()) && ((image->getHeight()) == ((*aLibraryIT).second)->getHeight()))
        {
            animationLibrary.emplace_back(animationLibrary.size()+1, image);
            system("clear");
        }
        else
        {
            system("clear");
            std::cout << "Zadaj obrazok rovnakej velkosti" << std::endl;
        }
    }
}
void CAnimation::printAnimationLibrary() const
{
    for (const auto & animationIT : animationLibrary)
        std::cout << "[" << animationIT.first << "] " << (animationIT.second)->getName() << std::endl;
}
int CAnimation::indexInput() const
{
    int index;
    std::cout << "Zadaj cislo obrazku co chces, vymazat" << std::endl;
    printAnimationLibrary();
    while (!(std::cin >> index))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Zadaj nezaporne cislo " << std::endl;
        if (index > getAnimationSize())
            std::cout << "Taky obrazok nemame" << std::endl;
    }
    return index;
}
void CAnimation::updateNumbers()
{
    if (getAnimationSize())
        for (int i = 0; i < getAnimationSize() ; i++)
            animationLibrary[i].first = i + 1;
}

void CAnimation::deleteImageFromAnimation()
{
    int index = indexInput();
    for (auto animationIT = animationLibrary.begin(); animationIT != animationLibrary.end(); animationIT++)
    {
        if ((*animationIT).first == index)
        {
            animationLibrary.erase(animationIT);
            updateNumbers();
            break;
        }
    }
    std::cout << "Takyto image nemame :)" << std::endl;
}

std::string GetLineFromCin()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}

bool CAnimation::pauseAnimation()
{
    std::cout << "Zadaj resume pre znovuspustenie, delete pre zmazanie obrazku, quit pre ukoncenie" << std::endl;
    std::string input;
    while (true)
    {
        std::cin >> input;
        if (input == "resume")
            return true;
        if (input == "quit")
            return false;
        if (input == "delete")
        {
            if (getAnimationSize() == 1 )
                std::cout << "Nemozes zmazat jediny obrazok" << std::endl;
            else
            {
                deleteImageFromAnimation();
                startAnimation();
            }
        }
    }
}

int CAnimation::getAnimationSize() const
{
    return this->animationLibrary.size();
}

// https://gist.github.com/vmrob/ff20420a20c59b5a98a1?fbclid=IwAR0gQ9c0vksmyX8YjePozDGOIW_ngdtnuy4iCiUwxYRJokJ4KQKOOGzFNeo
void CAnimation::startAnimation()
{
    int max = getAnimationSize();
    int index = 0;
    auto future = std::async(std::launch::async, GetLineFromCin);
    while (true)
    {
        if (future.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            std::string line = future.get();
            future = std::async(std::launch::async, GetLineFromCin);
            if (line == "p")
                if (!pauseAnimation())
                    break;
            if (line == "q")
                break;
        }
        animationLibrary[index++].second->printImage();
        std::cout << "Zadaj p pre pauznutie animacie a q pre ukoncenie" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if (index == max)
            index = 0;
    }
}