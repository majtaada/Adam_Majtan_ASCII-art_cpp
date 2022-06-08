#include <string>
#include <iostream>
#include <filesystem>

int main() {
    std::string path= "../majtaada/examples/";
    for (const auto & entry : std::filesystem::directory_iterator(path))
    {
      std::cout << entry.path() << std::endl;
      std::string fileDir = entry.path();
      fileDir.erase(0,path.size());
      std::cout << fileDir << std::endl;
      
    }
}
