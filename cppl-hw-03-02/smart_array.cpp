#include "smart_array.h"
#include <iostream>
#include <string>



smart_array::smart_array(int item)
{
	s_arr = new int[item];
	size = item;
	current = 0;
	for (int i = 0; i < size; ++i)
	{
		s_arr[i] = 0;
	}
}

smart_array::~smart_array()
{
	delete[] s_arr;
}

void smart_array::add_element(int item)
{
	auto append_array = [](int* s_arr, int* size, int* current, int item)
	{
		int* new_arr = new int[*size * 2];
		for (int i = 0; i < *size; ++i)
		{
			new_arr[i] = s_arr[i];
		}
		new_arr[*size] = item;
		++(*current);
		(*size) = *size * 2;
		delete[] s_arr;
		return new_arr;
	};

	if (current < size)
	{
		s_arr[current] = item;
		++current;
	}
	else
	{
		s_arr = append_array(s_arr, &size, &current, item);
		delete[] new_arr;
	}
}

int smart_array::get_element(int item)
{
	if (item >= current)
	{
		throw std::exception("ОШИБКА. Превышен размер использованного пространства массива");
	}
	if (item < 0)
	{
		throw std::exception("ОШИБКА. Индекс массива не корректен");
	}
	return s_arr[item];
}

int smart_array::get_current()
{
	return current;
}

int smart_array::get_size()
{
	return size;
}

smart_array& smart_array::operator = (const smart_array& r_arr)
{
	if (this != &r_arr)
	{
		this->size = r_arr.size;
		this->current = r_arr.current;
		this->s_arr = new int[r_arr.size];

		for (int i = 0; i < current; i++)
		{
			this->s_arr[i] = r_arr.s_arr[i];
		}
	}
	return *this;
}

smart_array::smart_array(const smart_array& r_arr)
{
	this->size = r_arr.size;
	this->current = r_arr.current;
	this->s_arr = new int[r_arr.size];

	for (int i = 0; i < current; i++)
	{
		this->s_arr[i] = r_arr.s_arr[i];
	}
}