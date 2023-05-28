#include "CFileHandler.hpp"


void CFileHandler::printInvalid(const std::string &mess) {
    clearScreen();
    std::cout << mess << std::endl;
    std::cout << space << std::endl;
}

void CFileHandler::readDirectory(const std::string &fileType) {
    int cnt = 0;
    directoryMap = {};
    std::vector<std::string> files;
    for (const auto &entry: std::filesystem::directory_iterator(path)) {
        std::string fileDir = entry.path();
        fileDir.erase(0, path.size());
        if (fileDir.substr(fileDir.size() - FORMAT_LEN, 4) == fileType) {
            files.push_back(fileDir);
        }
    }
    std::sort(files.begin(),files.end());
    for (const auto& file : files ) {
        directoryMap[++cnt] = file;
        std::cout << "[" << cnt << "] " << file << std::endl;
    }
    std::cout << space << std::endl;
}

std::string CFileHandler::readInput() {
    clearScreen();
    while (true) {
        std::string fileName;
        std::string fileRead;
        std::cout << "Zadaj cislo obrazku, ktory chces nacitat" << std::endl;
        std::cout << space << std::endl;
        readDirectory(".png");
        fileRead = getInputNumber();
        if(fileRead.empty())
            return "";
        fileName = path + fileRead;
        std::fstream file(fileName);
        if (!checkIfFileValid(fileName))
            printInvalid("Neplatny file skus iny");
        else
            return fileName;
    }
}

bool CFileHandler::checkIfFileValid(const std::string &name)  {
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
    int cnt = 0;
    if (ascii) {
        while (std::getline(txtFile, line)) {
            if(++cnt == 2)
                return false;
            asciiLevel = line;

        }
        if (asciiLevel.empty()) {
            txtFile.close();
            return false;
        }
        converter = std::make_shared<CTool>(asciiLevel);
    } else {
        if (!handleKernelFile(txtFile))
            return false;
    }
    return true;
}

bool CFileHandler::handleKernelFile(std::ifstream &txtFile) {
    kernel = {};
    std::string line;
    double val;
    if (txtFile.peek() == std::ifstream::traits_type::eof()) {
        return false;
    }
    while (std::getline(txtFile, line)) {
        std::vector<double> v1;
        std::stringstream ss(line);
        std::string number;
        while (std::getline(ss, number, ',')) {
            try {
                val = stod(number);
            } catch (...) {
                return false;
            }
            v1.push_back(val);
        }
        kernel.push_back(v1);
    }
    if (kernel.size() != kernel[0].size())
        return false;
    return true;
}
void CFileHandler::clearScreen() {
    system("clear");
}

std::vector<std::vector<double>> CFileHandler::readKernel() {
    clearScreen();
    while (true) {
        std::string fileName = "";
        std::cout << "Vyber si kernel" << std::endl;
        std::cout << space << std::endl;
        readDirectory(".txt");
        fileName = getInputNumber();
        if (fileName.size() < 5 || fileName.substr(fileName.size() - FORMAT_LEN, 4) != ".txt")
            printInvalid("To neni .txt");
        else if (!checkIfFileValid(path + fileName))
            printInvalid("Nefunkcny txt, skus iny");
        else {
            if (readTxtFile(fileName, false))
                return this->kernel;
            else
                printInvalid("Neplatny kernel, skus iny");
        }
    }
}
int CFileHandler::tryNumber(const std::string& fileNum) {
    int num = 0;
    try {
        num = stoi(fileNum);
    } catch (...) {
        return num;
    }
    return num;
}

std::string CFileHandler::getInputNumber() {
    std::string fileNum;
    int num;
    std::cin >> fileNum;
    if(std::cin.fail())
        return "";
    num = tryNumber(fileNum);
    if (directoryMap.find(num) != directoryMap.end())
        return directoryMap.at(num);
    return fileNum;
}

bool CFileHandler::initializeAsciiTransition() {
    while (true) {
        std::cout << "Zadaj cislo ascii prechodu" << std::endl;
        std::cout << space << std::endl;
        std::string fileName;
        readDirectory(".txt");
        fileName = getInputNumber();
        if(fileName.empty()) {
            std::cout << "Koniec inputu" << std::endl;
            return false;
        }
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
   clearScreen();
    return true;
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
        fclose(imageFile);
        return nullptr;
    }
    std::shared_ptr<CImage> image = std::make_shared<CImage>(imageMatrix, converter,
                                                             imageName.substr(path.size(), imageName.size()));
    fclose(imageFile);
    return image;
}


