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
	int size;		// ������ �������
	int current;	// ������ ��������������� ������������ �������
	int* s_arr;		// ��������� �� ������
	int* new_arr;	// ��������� �� ����������� ������
};