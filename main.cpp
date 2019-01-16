#include <iostream>
#include "Base64.h"

/*
 * Test data...
 */
int main() {
    Base64::Base64 objE;
    std::cout << objE.encode64("kljlkj") << std::endl;

    Base64::Base64 objD;
    std::cout << objD.decode64("SktMOUhKREgyamtqamtqazEyMw==") << std::endl;

    return 0;
}