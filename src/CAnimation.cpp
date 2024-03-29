#include "CAnimation.hpp"

void CAnimation::addImage(const std::shared_ptr<CImage> &image) {
    auto aLibraryIT = animationLibrary.begin();
    if (aLibraryIT == animationLibrary.end())
        animationLibrary.emplace_back(animationLibrary.size() + 1, image);
    else {
        if (((image->getWidth()) == ((*aLibraryIT).second)->getWidth()) &&
            ((image->getHeight()) == ((*aLibraryIT).second)->getHeight())) {
            animationLibrary.emplace_back(animationLibrary.size() + 1, image);
            system("clear");
        } else {
            system("clear");
            std::cout << "Zadaj obrazok rovnakej velkosti" << std::endl;
        }
    }
}

void CAnimation::printAnimationLibrary() const {
    for (const auto &animationIT: animationLibrary)
        std::cout << "[" << animationIT.first << "] " << (animationIT.second)->getName() << std::endl;
}

int CAnimation::indexInput() const {
    int index;
    std::cout << space << std::endl;
    std::cout << "Zadaj cislo obrazku co chces, vymazat" << std::endl;
    printAnimationLibrary();
    std::cout << space << std::endl;
    while (true) {
        std::cin >> index;
        if (std::cin.eof())
            return -1;
        if (index == 0) {
            std::cout << "Zadaj ine cislo ako 0 " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (std::cin.fail() || index > getAnimationSize()) {
            std::cout << "Zadaj cislo 1-" << getAnimationSize() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return index;
        }
    }
}

void CAnimation::updateNumbers() {
    if (getAnimationSize())
        for (int i = 0; i < getAnimationSize(); i++)
            animationLibrary[i].first = i + 1;
}

bool CAnimation::deleteImageFromAnimation() {
    int index = indexInput();
    if(index == - 1)
        return false;
    animationLibrary.erase(animationLibrary.begin() + index - 1);
    updateNumbers();
    return true;
}

std::string GetLineFromCin() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

bool CAnimation::pauseAnimation() {
    std::string input;
    while (true) {
        std::cout << "Zadaj resume pre znovuspustenie, delete pre zmazanie obrazku, quit pre ukoncenie" << std::endl;
        std::cin >> input;
        if (std::cin.fail())
            return false;
        if (input == "resume")
            return true;
        if (input == "quit")
            return false;
        if (input == "delete") {
            if (getAnimationSize() == 1)
                std::cout << "Nemozes zmazat jediny obrazok" << std::endl;
            else
                if(deleteImageFromAnimation());
        }
    }
}

int CAnimation::getAnimationSize() const {
    return this->animationLibrary.size();
}

// https://gist.github.com/vmrob/ff20420a20c59b5a98a1?fbclid=IwAR0gQ9c0vksmyX8YjePozDGOIW_ngdtnuy4iCiUwxYRJokJ4KQKOOGzFNeo
void CAnimation::startAnimation() {
    int max;
    int index = 0;
    auto future = std::async(std::launch::async, GetLineFromCin);
    while (true) {
        max = getAnimationSize();
        if (future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            std::string line = future.get();
            future = std::async(std::launch::async, GetLineFromCin);
            if (line == "p") {
                if (!pauseAnimation()) {
                    break;
                } else
                    index = 0;
            }
        }
        animationLibrary[index++].second->printImage();
        std::cout << "Zadaj p pre pauznutie animacie" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(350));
        if (index == max)
            index = 0;
    }
}

std::vector<std::shared_ptr<CImage>> CAnimation::getAnimationSet() {
    std::vector<std::shared_ptr<CImage>> images(animationLibrary.size());
    std::transform(animationLibrary.begin(), animationLibrary.end(), images.begin(),
                   [](const std::pair<int, std::shared_ptr<CImage>> &pair) {
                       return pair.second;
                   });
    return images;
}
