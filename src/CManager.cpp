#include "CManager.hpp"

const std::map<std::string, std::shared_ptr<CEffect>> CManager::mapEffect =
        {{"darken",      std::make_shared<CEffectDarken>()},
         {"lighten",     std::make_shared<CEffectLighten>()},
         {"negative",    std::make_shared<CEffectNegative>()},
         {"convolution", std::make_shared<CEffectConvolution>()},
         {"shrink",      std::make_shared<CEffectShrink>()}};

void CManager::addImage(CFileHandler &fr) {
    system("clear");
    std::shared_ptr<CImage> image = fr.readPNG(fr.readInput());
    if (image)
        library.addImage(image);
}

void CManager::print() {
    std::cout << "Zadaj meno obrazku (.png) alebo cislo obrazku, ktory chces vybrat" << std::endl;
    library.printLibrary();
    std::cout << bigSpace << std::endl;
    std::cout << "! AK SA TI OBRAZOK ZOBRAZI ZLE , SKUS ODZOOMOVAT ALEBO POUZIT EFEKT KONVOLUCE!" << std::endl;
    std::cout << bigSpace << std::endl;
}

std::string CManager::getNameInput() {
    print();
    std::string inputString;
    std::cin >> inputString;
    return inputString;
}

void CManager::showImage(std::string &name) {
    while (true) {
        std::shared_ptr<CImage> image = handleInput(name);
        if (!image) {
            system("clear");
            std::cout << "Taky obrazok nemame, skus iny" << std::endl;
            break;
        } else {
            image->printImage();
            break;
        }
    }
}

void CManager::setOfImages(int numOfImages) {
    std::vector<std::shared_ptr<CImage>> images;
    for (int i = 0; i < numOfImages; i++) {
        system("clear");
        nameInput = getNameInput();
        while (true) {
            std::shared_ptr<CImage> image = handleInput(nameInput);
            if (!image) {
                system("clear");
                std::cout << "Taky obrazok nemame, skus iny" << std::endl;
            } else {
                images.push_back(image);
                break;
            }
        }
    }
    useEffect(images);
}

void CManager::useEffect(const std::vector<std::shared_ptr<CImage>> &images) {
    system("clear");
    std::cout << "Zadaj meno efektu: darken, lighten, negative, shrink, convolution" << std::endl;
    std::cout << bigSpace << std::endl;
    std::string effectName;
    std::cin >> effectName;
    if (mapEffect.find(effectName) != mapEffect.end()) {
        for (const auto &image: images)
            mapEffect.at(effectName)->applyEffect(image);
        system("clear");
        std::cout << "Efekt bol pouzity" << std::endl;
    }
    else {
        system("clear");
        std::cout << "Takyto efekt nemame" << std::endl;
    }
}


bool CManager::checkIfInputNumber(const std::string &inputString) {
    auto it = inputString.begin();
    while (it != inputString.end() && std::isdigit(*it))
        ++it;
    return !inputString.empty() && it == inputString.end();
}

void CManager::deleteImage() {
    while (true) {
        system("clear");
        std::cout << "Zadaj meno alebo cislo obrazku co chces vymazat" << std::endl;
        library.printLibrary();
        std::string inputString;
        std::cin >> inputString;
        if (checkIfInputNumber(inputString)) {
            if (library.deleteImageFromLibrary(stoi(inputString)))
                break;
        } else {
            if (library.deleteImageFromLibrary(inputString))
                break;
        }
    }
}

std::shared_ptr<CImage> CManager::handleInput(std::string &name) const {
    if (checkIfInputNumber(name)) {
        std::shared_ptr<CImage> image = library.findImage(stoi(name));
        if (!image)
            return nullptr;
        return image;
    } else {
        std::shared_ptr<CImage> image = library.findImage(name);
        if (!image)
            return nullptr;
        return image;
    }
}

void CManager::animationPrints(CAnimation &animation) const {
    std::string name;
    while (true) {
        std::cout << "Zadaj nazov obrazku, ktory chces pridat do animacie , ak chces spustit animaciu zadaj start"
                  << std::endl;
        library.printLibrary();
        std::cout << bigSpace << std::endl;
        std::cin >> name;
        if (name == "start")
            break;
        std::shared_ptr<CImage> image = handleInput(name);
        if (!image) {
            system("clear");
            std::cout << "Taky obrazok nemame, skus iny" << std::endl;
        } else {
            system("clear");
            animation.addImage(image);
        }
    }
}

void CManager::initializeAnimation() const {
    CAnimation animation;
    animationPrints(animation);
    animation.startAnimation();
}

void CManager::printMenu() {
    std::cout << bigSpace << bigSpace << std::endl;
    std::cout
            << "Zadaj pismeno, o - na pridanie obrazka, i - na zobrazenie obrazku, s - na ulozenie obrazku, e - na pouzitie efektu , a - pre animaciu , z - na zmazanie , q na ukoncenie "
            << std::endl;
    std::cout << bigSpace << bigSpace << std::endl;
}

bool CManager::zeroImages() const {
    if (!library.getLibrarySize()) {
        system("clear");
        std::cout << "Potrebujes aspon jeden obrazok" << std::endl;
        return true;
    }
    return false;
}

int CManager::getNumberOfImages() {
    unsigned int inputInt;
    int libSize = library.getLibrarySize();
    std::cout << "Zadaj cislo na kolko obrazkov chces pouzit efekt" << std::endl;
    while (true) {
        std::cin >> inputInt;
        if (std::cin.fail() || inputInt > libSize) {
            system("clear");
            std::cout << "Zadaj cislo mensie ako pocet nasich obrazkov(" << libSize << ")" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return inputInt;
}

void CManager::saveImage(std::string &name) {
    while (true) {
        std::shared_ptr<CImage> image = handleInput(name);
        if (!image) {
            system("clear");
            std::cout << "Taky obrazok nemame, skus iny" << std::endl;
            break;
        } else {
            fileHandler.saveImage(image);
            system("clear");
            std::cout << "Obrazok bol uloženy ako " << image->getName() << std::endl;
            break;
        }
    }
}

void CManager::initializeProgram() {
    system("clear");
    fileHandler.initializeAsciiTransition();
    system("clear");
    char key = 'o';
    while (key != 'q') {
        printMenu();
        if (std::cin.eof())
            key = 'q';
        else
            std::cin >> key;
        switch (key) {
            case 'o': {
                addImage(fileHandler);
                break;
            }
            case 'i': {
                if (zeroImages())
                    break;
                nameInput = getNameInput();
                showImage(nameInput);
                break;
            }
            case 'e': {
                if (zeroImages())
                    break;
                int numberOfImages = getNumberOfImages();
                setOfImages(numberOfImages);
                break;
            }
            case 's': {
                if (zeroImages())
                    break;
                nameInput = getNameInput();
                saveImage(nameInput);
                break;
            }
            case 'a': {
                if (zeroImages())
                    break;
                initializeAnimation();
                break;
            }
            case 'z': {
                if (zeroImages())
                    break;
                deleteImage();
                break;
            }
            case 'q':
                break;
            default: {
                system("clear");
                std::cout << "Zadaj jedno z tychto pismen" << std::endl;
                break;
            }
        }
    }
}
