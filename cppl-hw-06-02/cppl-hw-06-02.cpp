#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "[IN]" << std::endl;
    int num;
    std::cin >> num;
    std::set<int> data;
    int d;
    for (int i = 0; i < num; ++i)
    {
        std::cin >> d;
        data.insert(d);
    }

    std::vector<int> result;
    for (const auto& i : data)  // почему здесь const?
    {
        result.push_back(i);
    }

    std::sort(begin(result), end(result), [](const int& a, const int& b) { return a > b; }); // почему здесь const?

    std::cout << "[OUT]" << std::endl;
    for (const auto& i : result) // почему здесь const?
    {
        std::cout << i << std::endl;
    }
}