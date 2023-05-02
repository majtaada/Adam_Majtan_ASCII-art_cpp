#include "CFileReader.hpp"

#define FORMAT_LEN 4

void CFileReader::readDirectory(std::string fileType) const
{
  for (const auto &entry : std::filesystem::directory_iterator(path))
  {
    std::string fileDir = entry.path();
    fileDir.erase(0, path.size());
    if (fileDir.substr(fileDir.size() - FORMAT_LEN, 4) == fileType)
      std::cout << fileDir << std::endl;
  }
}

std::string CFileReader::readInput() const
{
  system("clear");
  while (true)
  {
    std::string fileName;
    std::string fileRead;
    std::cout << "Zadaj image name .png, ktory chces nacitat" << std::endl;
    readDirectory(".png");
    std::cout << space << std::endl;
    std::cin >> fileRead;
    fileName = path + fileRead;
    std::fstream file(fileName);
    if (!checkIfFileValid(fileName))
      std::cout << "Neplatny file skus iny" << std::endl;
    else
    {
      return fileName;
      break;
    }
  }
}

bool CFileReader::checkIfFileValid(const std::string &name) const
{
  if (FILE *file = fopen(name.c_str(), "r"))
  {
    fclose(file);
    return true;
  }
  else
  {
    return false;
  }
}
bool CFileReader::readTxtFile(std::string & fileName, bool ascii)
{
  std::ifstream txtFile;
  std::string line;
  txtFile.open(path + fileName);
  if (ascii)
  {
    while (std::getline(txtFile, line))
    {
      asciiLevel += line;
    }
    if (asciiLevel.empty())
    {
      system("clear");
      std::cout << "Prazdny txt, skus iny" << std::endl;
      std::cout << space << std::endl;
      return false;
    }
    converter = std::make_shared<CTool>(asciiLevel);
  }
  else
  {
    if(!handleFile(txtFile,line))
      return false;
    return true;
  }
  return true;
}

bool CFileReader::handleFile(std::ifstream & txtFile, std::string & line)
{
  size_t lineSize = 0;
  while (std::getline(txtFile, line))
  {
    std::vector<double> v1;
    std::stringstream ss(line);
    std::string number;
    lineSize = line.size();
    while (std::getline(ss, number, ',')) {
      try {
          double val = stod(number);
          } catch (...) {
              std::cout << "Neplatny kernel , skus iny" << std::endl;
              std::cout << space << std::endl;
              return false;
          }
      v1.push_back(stod(number));
    }
    kernel.push_back(v1);
  }
  if (kernel.size() != kernel[0].size())
  {
    std::cout << "Neplatny kernel, skus iny" << std::endl;
    std::cout << space << std::endl;
    return false;
  }
  return true;
}

std::vector<std::vector<double>> CFileReader::readKernel()
{
  while (true)
  {
    std::string fileName;
    readDirectory(".txt");
    getline(std::cin, fileName);
    if (fileName.size() < 5 || fileName.substr(fileName.size() - FORMAT_LEN, 4) != ".txt")
    {
    }
    else if (!checkIfFileValid(path + fileName))
    {
    }
    else
    {
      if (readTxtFile(fileName, false))
      {
        return this->kernel;
      }
      else{
        //nejake printy, ze neplatny kernel
      }
      
    }
  }
}

void CFileReader::initializeAsciiTransition()
{
  while (true)
  {
    std::cout << "Zadaj ascii prechod (.txt)" << std::endl;
    std::string fileName;
    readDirectory(".txt");
    std::cout << space << std::endl;
    getline(std::cin, fileName);
    if (fileName.size() < 5 || fileName.substr(fileName.size() - FORMAT_LEN, 4) != ".txt")
    {
      system("clear");
      std::cout << "To neni .txt " << std::endl;
      std::cout << space << std::endl;
    }
    else if (!checkIfFileValid(path + fileName))
    {
      system("clear");
      std::cout << "Nefunkcny txt, skus iny" << std::endl;
      std::cout << space << std::endl;
    }
    else
    {
      if (readTxtFile(fileName, true))
        break;
      //nejaky print ze zly txt
    }
  }
}

std::shared_ptr<CImage> CFileReader::readPNG(const std::string &imageName)
{
  FILE *imageFile = fopen(imageName.c_str(), "r");
  png_structp pngStr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  png_infop pngInfo = png_create_info_struct(pngStr);
  png_init_io(pngStr, imageFile);
  png_read_png(pngStr, pngInfo, PNG_TRANSFORM_IDENTITY, NULL);
  try
  {
    imageMatrix = converter->toGrayScale(pngStr, pngInfo);
  }
  catch (std::invalid_argument &)
  {
    return nullptr;
  }
  std::shared_ptr<CImage> image = std::make_shared<CImage>(imageMatrix, converter, imageName.substr(path.size(), imageName.size()));
  fclose(imageFile);
  return image;
}
