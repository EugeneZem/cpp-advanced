#include <iostream>
#include <vector>

template <class T>
T mult (T in)
{
	return in * in;
}

template <>
std::vector<int> mult(std::vector<int> in)
{
	for (int n = 0; n < in.size(); ++n)
	{
		in[n] = in[n] * in[n];
	}
	return in;
}

int main()
{
	int v1 = 4;
	std::cout << "[IN]: " << v1 << std::endl;
	std::cout << "[OUT]: " << mult(v1) << std::endl;

	std::vector<int> v2(3);
	v2[0] = -1, v2[1] = 4, v2[2] = 8;

	std::cout << "[IN]: ";
	for (int el : v2)
	{
		std::cout << " " << el << ",";
	}
	std::cout << std::endl;
	v2 = mult(v2);
	std::cout << "[OUT]: ";
	for (int el : v2)
	{
		std::cout << " " << el << ",";
	}
	std::cout << std::endl;
}
