#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> dublicatClear(std::vector<int>);
void print(std::string, std::vector<int>);

int main()
{
    std::vector<int> vec { 1, 1, 2, 5, 6, 1, 2, 4 };
    std::vector<int>::iterator it = vec.begin();
    print("[IN]: ", vec);
    vec = dublicatClear(vec);
    print("[OUT]: ", vec);
}

std::vector<int> dublicatClear(std::vector<int> vec)
{
    std::sort(vec.begin(), vec.end());
    std::vector<int>::iterator it = std::unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
    return vec;
}

void print(std::string str, std::vector<int> vec)
{
    std::vector<int>::iterator it = vec.begin();
    std::cout << str;
    while (it != vec.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}