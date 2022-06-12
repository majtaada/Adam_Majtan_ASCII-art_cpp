#include "CManager.hpp"

const std::map<std::string, std::shared_ptr<CEffect>> CManager::mapEffect =
    {{"darken", std::make_shared<CEffectDarken>()},
     {"lighten", std::make_shared<CEffectLighten>()},
     {"negative", std::make_shared<CEffectNegative>()},
     {"convolution", std::make_shared<CEffectConvolution>()}};

void CManager::addImage(CFileReader &fr)
{
    system("clear");
    std::shared_ptr<CImage> image = fr.readPNG(fr.readInput());
    library.addImage(image);
}

void CManager::print()
{
    std::cout << "Zadaj meno obrazku (.png) alebo cislo obrazku , ktory chces vybrat" << std::endl;
    library.printLibrary();
    std::cout << bigSpace << std::endl;
    std::cout << "! AK SA TI OBRAZOK ZOBRAZI ZLE , SKUS ODZOOMOVAT ALEBO POUZIT EFEKT KONVOLUCE!" << std::endl;
    std::cout << bigSpace << std::endl;
}

std::string CManager::getNameInput()
{
    print();
    std::string inputString;
    std::cin >> inputString;
    return inputString;
}

void CManager::showImage(std::string &name)
{
    while (true)
    {
        std::shared_ptr<CImage> image = handleInput(name);
        if (!image)
        {
            std::cout << "Taky obrazok nemame, skus iny" << std::endl;
            break;
        }
        else
        {
            image->printImage();
            break;
        }
    }
}

void CManager::useEffect(std::string &string)
{
    while (true)
    {
        std::shared_ptr<CImage> image = handleInput(string);
        if (!image)
        {
            system("clear");
            std::cout << "Taky obrazok nemame, skus iny" << std::endl;
            break;
        }
        else
        {
            system("clear");
            std::cout << "Zadaj meno efektu: darken,lighten,convolution,negative" << std::endl;
            std::cout << bigSpace << std::endl;
            std::string effectName;
            std::cin >> effectName;
            if (effectName == "darken" || effectName == "lighten" || effectName == "convolution" || effectName == "negative")
            {
                mapEffect.at(effectName)->applyEffect(image);
                showImage(string);
                break;
            }
            std::cout << "Takyto efekt nemame" << std::endl;
        }
    }
}

bool CManager::checkIfInputNumber(const std::string &inputString) const
{
    auto it = inputString.begin();
    while (it != inputString.end() && std::isdigit(*it))
        ++it;
    return !inputString.empty() && it == inputString.end();
}

void CManager::deleteImage()
{
    while (true)
    {
        system("clear");
        std::cout << "Zadaj meno alebo cislo obrazku co chces vymazat" << std::endl;
        library.printLibrary();
        std::string inputString;
        std::cin >> inputString;
        if (checkIfInputNumber(inputString))
        {
            if (library.deleteImageFromLibrary(stoi(inputString)))
                break;
        }
        else
        {
            if (library.deleteImageFromLibrary(inputString))
                break;
        }
    }
}

std::shared_ptr<CImage> CManager::handleInput(std::string &name) const
{
    if (checkIfInputNumber(name))
    {
        std::shared_ptr<CImage> image = library.findImage(stoi(name));
        if (!image)
        {
            return nullptr;
        }
        else
        {
            return image;
        }
    }
    else
    {
        std::shared_ptr<CImage> image = library.findImage(name);
        if (!image)
        {
            return nullptr;
        }
        else
        {
            return image;
        }
    }
}

void CManager::animationPrints(CAnimation &animation) const
{
    std::string name;
    int flag = 0;
    while (true)
    {
        if (!flag)
            system("clear");
        flag = 0;
        std::cout << "Zadaj nazov obrazku, ktory chces pridat do animacie , ak chces spustit animaciu zadaj start" << std::endl;
        library.printLibrary();
        std::cout << bigSpace << std::endl;
        std::cin >> name;
        if (name == "start")
            break;
        std::shared_ptr<CImage> image = handleInput(name);
        if (!image)
        {
            system("clear");
            std::cout << "Taky obrazok nemame, skus iny" << std::endl;
            flag++;
        }
        else
            animation.addImage(image);
    }
}

void CManager::initializeAnimation() const
{
    CAnimation animation;
    animationPrints(animation);
    animation.startAnimation();
}

void CManager::printMenu() const
{
    std::cout << bigSpace << bigSpace << std::endl;
    std::cout << "Zadaj pismeno, o - na pridanie obrazka, i - na zobrazenie obrazku, e - na pouzitie efektu , a - pre animaciu , z - na zmazanie , q na ukoncenie " << std::endl;
    std::cout << bigSpace << bigSpace << std::endl;
}

bool CManager::zeroImages() const
{
    if (!library.getLibrarySize())
    {
        system("clear");
        std::cout << "Potrebujes aspon jeden obrazok" << std::endl;
        return true;
    }
    return false;
}

void CManager::initializeProgram()
{
    system("clear");
    filereader.initializeAsciiTransition();
    system("clear");
    while (key != 'q')
    {
        printMenu();
        std::cin >> key;
        switch (key)
        {
        case 'o':
        {
            addImage(filereader);
            break;
        }
        case 'i':
        {
            if (zeroImages())
                break;
            nameInput = getNameInput();
            showImage(nameInput);
            break;
        }
        case 'e':
        {
            if (zeroImages())
                break;
            nameInput = getNameInput();
            useEffect(nameInput);
            break;
        }
        case 'a':
        {
            if (zeroImages())
                break;
            initializeAnimation();
            break;
        }
        case 'z':
        {
            if (zeroImages())
                break;
            deleteImage();
            break;
        }
        case 'q':
            break;
        default:
        {
            system("clear");
            std::cout << "Zadaj jedno z tychto pismen" << std::endl;
            break;
        }
        }
    }
}
