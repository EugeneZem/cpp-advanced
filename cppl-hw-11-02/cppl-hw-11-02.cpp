#include <iostream>
#include "unending.h"

int main()
{
    auto num1 = unending("125");
    auto num2 = unending("125444");

    auto result1 = num1 + num2;
    std::cout << num1 << " + " << num2 << " = " << result1 << std::endl;

    auto result2 = num1 * num2;
    std::cout << num1 << " * " << num2 << " = " << result2 << std::endl;

    auto num3 = num1;
    auto result3 = num1 * num3;
    std::cout << num1 << " * " << num3 << " = " << result3 << std::endl;

    num3 = unending(result2);
    std::cout << num3 << " + " << result2 << " = ";
    result2 = num3 + result2;
    std::cout << result2 << std::endl;

}