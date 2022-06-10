#include "CManager.hpp"

const std::map < std::string , CEffect * > CManager::mapEffect =
                            {{ "darken" , new CEffectDarken()},
                             { "lighten" , new CEffectLighten()},
                             { "negative" , new CEffectNegative()},
                             { "convolution" , new CEffectConvolution()}};

void CManager::addImage(CFileReader & fr)
{   
    system("clear");
    CImage * image = fr.readPNG(fr.readInput());
    library.addImage(image);
}

void CManager::print() 
{
    std::cout << "Zadaj image name .png, ktory chces zobrazit" << std::endl;
    library.printLibrary();
    std::cout << space << space << space << std::endl;
    std::cout << "!! AK SA TI OBRAZOK ZOBRAZI ZLE , SKUS ODZOOMOVAT ALEBO POUZIT EFEKT KONVOLUCE !!" << std::endl;
    std::cout << space << space << space << std::endl;
}

std::string CManager::getNameInput() 
{
    print();
    std::cin >> imageName;
    return imageName;
}

void CManager::showImage(std::string &imageName)
{
    CImage * image = library.findImage(imageName);
    image->printImage();
}

void CManager::useEffect(std::string &imageName)
{
    CImage * image = library.findImage(imageName);
    system("clear");
    std::cout << "Zadaj meno efektu: darken,lighten,convolution,negative" << std::endl;
    std::cout << space <<  space << std::endl;
    std::string effectName;
    std::cin >> effectName;
    mapEffect.at(effectName)->applyEffect(image);
    
    showImage(imageName);

}

void CManager::deleteImage(std::string &imageName)
{
    library.deleteImageFromLibrary(imageName);
}

void CManager::animationPrints(CAnimation & animation) const
{
    std::string imageName;
    while(1)
    {
        system("clear");
        std::cout << "Zadaj nazov obrazku, ktory chces pridat do animacie , ak chces spustit animaciu zadaj s" << std::endl;
        library.printLibrary();
        std::cout << space << space << std::endl;
        std::cin >> imageName;
        if(imageName == "s" ) break;
        animation.addImage(library.findImage(imageName));
    }
}

void CManager::initializeAnimation() const
{
    CAnimation animation;
    animationPrints(animation);
    animation.startAnimation();   
}

void CManager::initializeProgram()
{
    system("clear");
    filereader.initializeAsciiTransition();
    while(key != 'q')
    {   
        std::cout << "Zadaj pismeno, o - na pridanie obrazka, i - na zobrazenie obrazku, e - na pouzitie efektu , a - pre animaciu , z - na zmazanie , q na ukoncenie " << std::endl;
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

            }
        }

    }
    library.~CImageLibrary();
    
}
