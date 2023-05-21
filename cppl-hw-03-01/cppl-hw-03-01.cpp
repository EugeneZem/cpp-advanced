#include <iostream>
#include "smart_array.h"

int main()
{
	setlocale(LC_ALL, "ru-RU");
	system("chcp 1251");

	try
	{
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		arr.add_element(18);

	//	smart_array qw = arr;

		std::cout << arr.get_element(0) << std::endl;
		std::cout << arr.get_element(1) << std::endl;
		std::cout << arr.get_element(2) << std::endl;
		std::cout << arr.get_element(3) << std::endl;
		std::cout << arr.get_element(4) << std::endl;
		std::cout << arr.get_element(5) << std::endl;
		std::cout << arr.get_element(6) << std::endl;
	}
	catch (const std::exception& ex)
	{
			std::cout << ex.what() << std::endl;
	}
}