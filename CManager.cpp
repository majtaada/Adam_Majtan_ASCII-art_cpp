#include "CManager.hpp"


void CManager::addImage()
{   
    system("clear");
    CFileReader * fr = new CFileReader;
    CImage image = fr->readPNG(fr->readInput());
    library.addImage(image);
}

void CManager::showImage()
{
    system("clear");
    std::cout << "zadaj image name" << std::endl;
    library.printLibrary();
    std::cout << "===================" << std::endl;
    std::cin >> imageName;
    CImage image = library.findImage(imageName);
    image.printImage();
    std::cout << image.getGraylevel() << std::endl;
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
            addImage();
            break;
            }
        case 'i':
            {
            showImage();
            break;
            }
        default:
            break;
        }
    }
}
