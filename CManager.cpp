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
    // system("clear");
    CImage * image = library.findImage(imageName);
    image->printImage();
}

void CManager::useEffect(std::string &imageName)
{
    // system("clear");
    CImage * image = library.findImage(imageName);
    std::cout << "Zadaj meno efektu, (darken,lighten,convolution,negative)" << std::endl;
    std::string effectName;
    std::cin >> effectName;
    mapEffect.at(effectName)->applyEffect(image);
    
    showImage(imageName);

}

void CManager::deleteImage(std::string &imageName)
{
    library.deleteImagefromLibrary(imageName);
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
}
