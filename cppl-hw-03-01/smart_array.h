#pragma once

class smart_array
{
public:
	smart_array(const smart_array&) = delete;
	smart_array& operator = (const smart_array&) = delete;

	smart_array(int);
	~smart_array();
	void add_element(int);
	int get_element(int);
	int get_current();
	int get_size();
private:
	int size;		// размер массива
	int current;	// размер использованного пространства массива
	int* s_arr;		// указатель на массив
	int* new_arr;	// указатель на увеличенный массив
};