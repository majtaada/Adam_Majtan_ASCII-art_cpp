#include "CManager.hpp"

const std::map < std::string , std::shared_ptr<CEffect>> CManager::mapEffect =
                            {{ "darken" ,  std::make_shared<CEffectDarken>()},
                             { "lighten" , std::make_shared<CEffectLighten>()},
                             { "negative" , std::make_shared<CEffectNegative>()},
                             { "convolution" , std::make_shared<CEffectConvolution>()}};

void CManager::addImage(CFileReader & fr)
{   
    system("clear");
    std::shared_ptr<CImage>  image =  fr.readPNG(fr.readInput());
    library.addImage(image);
}

void CManager::print() 
{
    std::cout << "Zadaj image name .png, ktory chces zobrazit" << std::endl;
    library.printLibrary();
    std::cout << bigSpace << std::endl;
    std::cout << "! AK SA TI OBRAZOK ZOBRAZI ZLE , SKUS ODZOOMOVAT ALEBO POUZIT EFEKT KONVOLUCE!" << std::endl;
    std::cout << bigSpace << std::endl;
}

std::string CManager::getNameInput() 
{
    print();
    std::cin >> imageName;
    return imageName;
}

void CManager::showImage(std::string &name)
{
    std::shared_ptr<CImage> image = library.findImage(name);
    image->printImage();
}

void CManager::useEffect(std::string &string)
{
    std::shared_ptr<CImage> image = library.findImage(string);
    system("clear");
    std::cout << "Zadaj meno efektu: darken,lighten,convolution,negative" << std::endl;
    std::cout << bigSpace << std::endl;
    std::string effectName;
    std::cin >> effectName;
    mapEffect.at(effectName)->applyEffect(image);
    
    showImage(string);

}

void CManager::deleteImage(std::string &name)
{
    library.deleteImageFromLibrary(name);
}

void CManager::animationPrints(CAnimation & animation) const
{
    std::string name;
    while(true)
    {
        system("clear");
        std::cout << "Zadaj nazov obrazku, ktory chces pridat do animacie , ak chces spustit animaciu zadaj s" << std::endl;
        library.printLibrary();
        std::cout << bigSpace << std::endl;
        std::cin >> name;
        if(name == "s" ) break;
        animation.addImage(library.findImage(name));
    }
}

void CManager::initializeAnimation() const
{
    CAnimation animation;
    animationPrints(animation);
    animation.startAnimation();   
}

void CManager::printAnimation() const
{
    std::cout << bigSpace << bigSpace << std::endl;
    std::cout << "Zadaj pismeno, o - na pridanie obrazka, i - na zobrazenie obrazku, e - na pouzitie efektu , a - pre animaciu , z - na zmazanie , q na ukoncenie " << std::endl;
    std::cout << bigSpace << bigSpace << std::endl;
}

void CManager::initializeProgram()
{
    system("clear");
    filereader.initializeAsciiTransition();
    system("clear");
    while(key != 'q')
    {   
        printAnimation();
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
            nameInput = getNameInput();
            showImage(nameInput);
            break;
            }
        case 'e':
            {
            nameInput = getNameInput();
            useEffect(nameInput);
            break;
            }
        case 'a':
            {
            initializeAnimation();
            break;
            }
        case 'z':
            {
            nameInput = getNameInput();
            deleteImage(nameInput);
            break;
            }
        default:
            {
            break;
            }
        }

    }
    
}
