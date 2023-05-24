#include "CManager.hpp"

const std::map<std::string, std::shared_ptr<CEffect>> CManager::mapEffect =
        {{"darken",      std::make_shared<CEffectDarken>()},
         {"lighten",     std::make_shared<CEffectLighten>()},
         {"negative",    std::make_shared<CEffectNegative>()},
         {"convolution", std::make_shared<CEffectConvolution>()},
         {"shrink",      std::make_shared<CEffectShrink>()}};

bool CManager::addImage(CFileHandler &fr) {
    system("clear");
    imageName = fr.readInput();
    if(imageName.empty())
        return false;
    std::shared_ptr<CImage> image = fr.readPNG(imageName);
    if (image){
        library.addImage(image);
        return true;
    }
    return false;
}

void CManager::print() {
    system("clear");
    std::cout << "Zadaj meno obrazku (.png) alebo cislo obrazku, ktory chces vybrat" << std::endl;
    library.printLibrary();
    std::cout << bigSpace << std::endl;
    std::cout << "! AK SA TI OBRAZOK ZOBRAZI ZLE , SKUS ODZOOMOVAT ALEBO POUZIT EFEKT SHRINK!" << std::endl;
    std::cout << bigSpace << std::endl;
}

std::string CManager::getNameInput() {
    print();
    printImagesSet();
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

void CManager::printImagesSet() const {
    if (images.empty())
        std::cout << "Zatial nemas ziadne zvolene obrazky" << std::endl;
    else {
        std::cout << "Zatial mas zvolene: ";
        for (int i = 0; i < images.size(); ++i) {
            std::cout << images[i]->getName();
            if (i != images.size() - 1)
                std::cout << ",";
        }
        std::cout << "\n";
    }
    std::cout << bigSpace << std::endl;
}

void CManager::setOfImages(int numOfImages) {
    images = {};
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

void CManager::useEffect(const std::vector<std::shared_ptr<CImage>> & cimages) {
    system("clear");
    std::cout << "Zadaj meno efektu: darken, lighten, negative, shrink, convolution" << std::endl;
    std::cout << bigSpace << std::endl;
    std::string effectName;
    std::cin >> effectName;
    if (mapEffect.find(effectName) != mapEffect.end()) {
        mapEffect.at(effectName)->applyEffect(cimages);
        system("clear");
        std::cout << "Efekt bol pouzity" << std::endl;
    } else {
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
        std::cout << bigSpace << std::endl;
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

void CManager::animationPrints(CAnimation &animation) {
    std::string name;
    system("clear");
    while (true) {
        std::cout << "Zadaj nazov obrazku, ktory chces pridat do animacie , ak chces spustit animaciu zadaj start"
                  << std::endl;
        images = animation.getAnimationSet();
        printImagesSet();
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

void CManager::initializeAnimation() {
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
    system("clear");
    std::cout << "Zadaj cislo na kolko obrazkov chces pouzit efekt" << std::endl;
    std::cout << bigSpace << std::endl;
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
    if (!fileHandler.initializeAsciiTransition())
        return;
    char key = 'o';
    while (key != 'q') {
        printMenu();
        if (std::cin.fail())
            key = 'q';
        else
            std::cin >> key;
        switch (key) {
            case 'o': {
                if(!addImage(fileHandler)) {
                    std::cout << "Koniec inputu" << std::endl;
                    return;
                }
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
                std::cout << "Koniec aplikacie!" << std::endl;
                break;
            default: {
                system("clear");
                std::cout << "Zadaj jedno z tychto pismen" << std::endl;
                break;
            }
        }
    }
}
