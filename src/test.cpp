#include <iostream>
#include <chrono>
#include <future>
#include <string>

std::string GetLineFromCin() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int main() {

    auto future = std::async(std::launch::async, GetLineFromCin);

    while (true) {
        if (future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto line = future.get();
            future = std::async(std::launch::async, GetLineFromCin);

            std::cout << "you wrote " << line << std::endl;
        }
        
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}