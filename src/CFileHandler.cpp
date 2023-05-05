#include "CFileHandler.hpp"

#define FORMAT_LEN 4

void CFileHandler::printInvalid(const std::string &mess) {
    system("clear");
    std::cout << mess << std::endl;
    std::cout << space << std::endl;
}


void CFileHandler::readDirectory(const std::string &fileType) const {
    for (const auto &entry: std::filesystem::directory_iterator(path)) {
        std::string fileDir = entry.path();
        fileDir.erase(0, path.size());
        if (fileDir.substr(fileDir.size() - FORMAT_LEN, 4) == fileType)
            std::cout << fileDir << std::endl;
    }
}

std::string CFileHandler::readInput() const {
    system("clear");
    while (true) {
        std::string fileName;
        std::string fileRead;
        std::cout << "Zadaj image name .png, ktory chces nacitat" << std::endl;
        readDirectory(".png");
        std::cout << space << std::endl;
        std::cin >> fileRead;
        fileName = path + fileRead;
        std::fstream file(fileName);
        if (!checkIfFileValid(fileName))
            printInvalid("Neplatny file skus iny");
        else
            return fileName;
    }
}

bool CFileHandler::checkIfFileValid(const std::string &name) const {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

bool CFileHandler::readTxtFile(std::string &fileName, bool ascii) {
    std::ifstream txtFile;
    std::string line;
    txtFile.open(path + fileName);
    if (ascii) {
        while (std::getline(txtFile, line)) {
            asciiLevel += line;
        }
        if (asciiLevel.empty()) {
            printInvalid("Prazdny txt, skus iny");
            return false;
        }
        converter = std::make_shared<CTool>(asciiLevel);
    } else {
        if (!handleFile(txtFile, line))
            return false;
    }
    return true;
}

bool CFileHandler::handleFile(std::ifstream &txtFile, std::string &line) {
    size_t lineSize = 0;
    while (std::getline(txtFile, line)) {
        std::vector<double> v1;
        std::stringstream ss(line);
        std::string number;
        lineSize = line.size();
        while (std::getline(ss, number, ',')) {
            try {
                double val = stod(number);
            } catch (...) {
                return false;
            }
            v1.push_back(stod(number));
        }
        kernel.push_back(v1);
    }
    if (kernel.size() != kernel[0].size())
        return false;
    return true;
}

std::vector<std::vector<double>> CFileHandler::readKernel() {
    system("clear");
    while (true) {
        std::string fileName = "";
        std::cout << "Vyber si kernel" << std::endl;
        std::cout << space << std::endl;
        readDirectory(".txt");
        std::cout << space << std::endl;
        getline(std::cin, fileName);
        if (fileName.size() < 5 || fileName.substr(fileName.size() - FORMAT_LEN, 4) != ".txt")
            printInvalid("To neni .txt");
        else if (!checkIfFileValid(path + fileName))
            printInvalid("Nefunkcny txt, skus iny");
        else {
            if (readTxtFile(fileName, false))
                return this->kernel;
            else
                printInvalid("Neplatnyy kernel, skus iny");
        }
    }
}

void CFileHandler::initializeAsciiTransition() {
    while (true) {
        std::cout << "Zadaj ascii prechod (.txt)" << std::endl;
        std::string fileName;
        readDirectory(".txt");
        std::cout << space << std::endl;
        getline(std::cin, fileName);
        if (fileName.size() < 5 || fileName.substr(fileName.size() - FORMAT_LEN, 4) != ".txt")
            printInvalid("To neni .txt");
        else if (!checkIfFileValid(path + fileName))
            printInvalid("Nefunkcny txt, skus iny");
        else {
            if (readTxtFile(fileName, true))
                break;
            printInvalid("Neplatny ascii prechod, skus iny");
        }
    }
}

void CFileHandler::saveImage(const std::shared_ptr<CImage> &image) {
    std::vector<std::vector<char>> asciiMatrix = image->getAsciiImage();
    std::string imageName = image->getName();
    std::ofstream outFile(imageName + ".txt");
    for (const auto &line: asciiMatrix) {
        for (const auto &ch: line) {
            outFile << ch;
        }
        outFile << '\n';
    }
    outFile.close();
}

std::shared_ptr<CImage> CFileHandler::readPNG(const std::string &imageName) {
    FILE *imageFile = fopen(imageName.c_str(), "r");
    png_structp pngStr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop pngInfo = png_create_info_struct(pngStr);
    png_init_io(pngStr, imageFile);
    png_read_png(pngStr, pngInfo, PNG_TRANSFORM_IDENTITY, NULL);
    try {
        imageMatrix = converter->toGrayScale(pngStr, pngInfo);
    }
    catch (std::invalid_argument &) {
        return nullptr;
    }
    std::shared_ptr<CImage> image = std::make_shared<CImage>(imageMatrix, converter,
                                                             imageName.substr(path.size(), imageName.size()));
    fclose(imageFile);
    return image;
}
