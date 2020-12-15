#include "Lab2.h"
#include "Lab3.h"

#include <iostream>

int main()
{
    std::string infix;
    std::getline(std::cin, infix);

    std::cout << calculateRpn(infixToRpn(infix)) << std::endl;

    return 0;
}

