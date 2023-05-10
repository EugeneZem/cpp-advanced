#include <iostream>

struct point 
{
private:
	int m_x;
	int m_y;

public:
	point(int x, int y) 
	{
		m_x = x;
		m_y = y;
	}
	void print_point() 
	{
		std::cout << "x:" << m_x << ", y: " << m_y << std::endl;
	}
};



int main()
{
	for (int i = 0; i < 5; ++i)
	{
		point my_point(i, 2 * i);
		my_point.print_point();
	}
	return 0;
}
