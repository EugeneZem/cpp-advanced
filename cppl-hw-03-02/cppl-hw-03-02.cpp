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

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

		//smart_array arr2(arr);
		//std::cout << arr2.get_element(0) << std::endl;
		//std::cout << arr2.get_element(1) << std::endl;

		std::cout << arr.get_element(0) << std::endl;
		std::cout << arr.get_element(1) << std::endl;

		std::cout << new_array.get_element(0) << std::endl;
		std::cout << new_array.get_element(1) << std::endl;


	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}