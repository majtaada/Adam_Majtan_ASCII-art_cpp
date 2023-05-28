#include "CManager.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

/**
 * @brief class for tests
 */

class CTests {
public:
    /**
     * function to call all tests;
     */
    void callTests();

private:
    /**
     * function for input tests
     */
    void checkingInputTests();

    /**
     * function for file tests
     */
    void checkingFileTests();
};
