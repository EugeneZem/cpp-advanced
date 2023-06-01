#include <iostream>
#include <vector>

template <typename T> std::vector<T> move_vectors(std::vector<T>&);

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    
    two = move_vectors(one);

    std::cout << two[1] << std::endl;
    
    if (!one.size()) std::cout << "vector moved";

}

template <typename T> std::vector<T> move_vectors(std::vector<T>& lval)
{
    std::vector<T> result =  std::move(lval);
    lval.clear();
    return result;
}   