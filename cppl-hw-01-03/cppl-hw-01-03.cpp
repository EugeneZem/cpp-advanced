#include <iostream>
#include <vector>
#include <math.h>
#include <functional>

int main()
{
	setlocale(LC_ALL, "ru-RU");
	system("chcp 1251");

	std::vector<int> angles { 30, 60, 90 };
	float PI = 3.1415926;

	std::cout << "[Входные данные]:" << std::endl;
	for (int angel : angles)
	{
		std::cout << angel << " * " << PI << " / 180,  ";
	}

	auto my_sin = [PI](int angel)
	{
		std::cout << " sin: " << sin(angel * PI / 180);
	};

	auto my_cos = [PI](int angel)
	{
		std::cout << " cos: " << cos(angel * PI / 180);
	};

	std::vector<std::function<void(int)>> functions;
	functions.emplace_back(my_sin);
	functions.emplace_back(my_cos);


	std::cout << std::endl << "[Выходные данные]: " << std::endl;
	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}
}