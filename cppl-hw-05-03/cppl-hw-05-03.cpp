#include <iostream>
#include <vector>

class MyFunctor
{
public:
    int get_sum()
    {
        return sum;
    }

    int get_count()
    {
       return count;
    }

    void operator ()(int a)
    {
        if (!(a % 3))
        {
            sum += a;
            ++count;
        }
    }

private:
    int sum = 0, count = 0;
};


int main()
{
    MyFunctor f;
    int arr[] = { 4, 1, 3, 6, 25, 54 };
    for (auto el : arr)
    {
        f(el);
    }
    std::cout << "get_sum() = " << f.get_sum() << std::endl;
    std::cout << "get_count() = " << f.get_count() << std::endl;
}