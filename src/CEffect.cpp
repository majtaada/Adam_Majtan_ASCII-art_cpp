#include "CEffect.hpp"

int CEffect::getValue() {
    int num;
    std::string numBuffer;
    std::cout << "Zadaj o kolko chces obrazok stmavit/zosvetlit (0 - 255)" << std::endl;
    while (true) {
        std::cin >> numBuffer;
        if(std::cin.eof())
            return -1;
        try {
            num = std::stoi(numBuffer);
        } catch (...) {}
        if( num < 0 || std::cin.fail()){
            std::cout << "Zadaj nezaporne cislo " << std::endl;
            std::cin.clear();
        }
        else{
            break;
        }
    }
    return num;
}

std::vector<std::vector<double>> CEffect::getKernel() {
    CFileHandler fileReader;
    return fileReader.readKernel();
}
