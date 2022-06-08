#include <CManager.hpp>


void CManager::initializeProgram()
{
    system("clear");
    CFileReader a;
    a.initializeAsciiTransition();
    while(key != 'q')
    {
        std::cout << "Zadaj pismeno, o - na pridanie obrazka, e - na pouzitie efektu , a - pre animaciu " << std::endl;
        std::cin >> key;
        switch (key)
        {
        case 'o':
            {
            CFileReader * fr = new CFileReader;
            CImage image = fr->readInput();
            
            break;
            }
        case 'e':

        default:
            break;
        }
    }
}
