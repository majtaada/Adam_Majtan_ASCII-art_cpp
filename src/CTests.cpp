#include "CTests.hpp"

void CTests::callTests() {
    checkingInputTests();
    checkingFileTests();
    std::cout << "All tests completed" << std::endl;
}

void CTests::checkingInputTests() {
    std::cout << "Testing inputs" << std::endl;
    assert(CManager::checkIfInputNumber("351") == true);
    assert(CManager::checkIfInputNumber("351a") == false);
    assert(CFileHandler::tryNumber("9")==9);
    assert(CFileHandler::tryNumber("a")==0);
}

void CTests::checkingFileTests() {
    std::cout << "Testing files" << std::endl;
    assert(CFileHandler::checkIfFileValid("/home/adam/PA2/semestralka/majtaada/examples/gaussiankernel.txt")==true);
}


