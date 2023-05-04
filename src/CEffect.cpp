#include "CEffect.hpp"

unsigned int CEffect::getValue()
{
    unsigned int value;
    std::cout << "Zadaj o kolko chces obrazok stmavit/zosvetlit" << std::endl;
    while (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Zadaj nezaporne cislo " << std::endl;
    }
    return value;
}

std::vector<std::vector<double>> CEffect::getKernel()
{
    CFileHandler fileReader;
    return fileReader.readKernel();   
}
