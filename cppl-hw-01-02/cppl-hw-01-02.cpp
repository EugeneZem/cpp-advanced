#include <iostream>
#include <vector>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant()
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	auto var = get_variant();

	if (std::holds_alternative<int>(var))
	{
		std::cout << std::get<int>(var) * 2;
	}
	else if (std::holds_alternative<std::string>(var))
	{
		std::cout << std::get<std::string>(var);
	}
	else
	{
		for(int num : std::get<std::vector<int>>(var))
			std::cout << num << " ";
	}
}