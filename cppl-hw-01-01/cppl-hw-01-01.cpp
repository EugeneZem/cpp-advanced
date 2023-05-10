#include <iostream>
#include <vector>

int main()
{
    setlocale(LC_ALL, "ru-RU");
    system("chcp 1251");

    std::vector <int> arr = { 4, 7, 9, 14, 12 };

    std::cout << "Входные данные: ";
    for (int num : arr)
    {
        std::cout << num << "  ";
    }
    
    auto mult3 = [arr]() mutable
    {
        for (int num : arr)
        {
            if (num % 2)
            {
                std::cout << num * 3 << "  ";
            }
            else
            {
                std::cout << num << "  ";
            }
        }
    };

    std::cout << std::endl << "Выходные данные: ";
    mult3();
}