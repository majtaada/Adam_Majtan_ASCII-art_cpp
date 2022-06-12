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
      std::ifstream txtFile;
      std::string line;
      txtFile.open(path + fileName);
      while (std::getline(txtFile, line))
      {
        asciiLevel += line;
      }
      break;
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
  imageMatrix = converter->toGrayScale(pngStr, pngInfo);
  converter = std::make_shared<CTool>(asciiLevel);
  std::shared_ptr<CImage> image = std::make_shared<CImage>(imageMatrix, converter, imageName.substr(path.size(), imageName.size()));
  fclose(imageFile);
  return image;
}
