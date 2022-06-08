#include "CManager.hpp"


void CManager::addImage(CFileReader & fr)
{   
    system("clear");
    CImage image = fr.readPNG(fr.readInput());
    library.addImage(image);
}

void CManager::print(CImageLibrary & library) const
{
    std::cout << "Zadaj image name .png, ktory chces zobrazit" << std::endl;
    library.printLibrary();
    std::cout << space << space << space << std::endl;
    std::cout << "!! AK SA TI OBRAZOK ZOBRAZI ZLE , SKUS ODZOOMOVAT ALEBO POUZIT EFEKT KONVOLUCE !!" << std::endl;
    std::cout << space << space << space << std::endl;
}

void CManager::showImage()
{
    system("clear");
    print(library);
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
            addImage(filereader);
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
