#include <iostream>

template <class T>
class table
{
public:
    table(int col, int row) : _col(col), _row(row), arr(new T* [_col])
    {
        for (int a = 0; a < _col; ++a)
        {
            arr[a] = new T[_row];
        }
    }

    ~table()
    {
        for (int a = 0; a < _col; ++a)
        {
            delete [] arr[a];
        }
        delete [] arr;
    }

    table& operator = (const table& rpar)
    {
        if (this != &rpar)
        {

            for (int a = 0; a < _col; ++a)
            {
                delete[] arr[a];
            }
            delete[] arr;

            _col = rpar._col;
            _row = rpar._row;

            arr = new T * [_col];
            for (int a = 0; a < _col; ++a)
            {
                arr[a] = new T[_row];
            }
            for (int a = 0; a < rpar._col; ++a)
            {
                for (int b = 0; b < rpar._row; ++b)
                {
                    arr[a][b] = rpar.arr[a][b];
                }
            }
        }
        return *this;
    }

    const T* operator [] (int i) const
    {
        return arr[i];
    }

    T* operator [] (int i)
    {
        return arr[i];
    }

    const int size() const
    {
        return _col * _row;
    }

    table(const table& rpar) : _col(rpar._col), _row(rpar._row), arr(new T* [_col])
    {
        for (int a = 0; a < _col; ++a)
        {
            arr[a] = new T[_row];
        }
        for (int a = 0; a < _col; ++a)
        {
            for (int b = 0; b < _row; ++b)
            {
                arr[a][b] = rpar.arr[a][b];
            }
        }
    }

private:
    int _col, _row;
    T** arr = nullptr;
};

int main()
{
    //auto test = table<int>(2, 3);
    table <int> test(2, 3);
    table <int> test2 = test;
    test[1][2] = 4;
    std::cout << test[1][2] << std::endl;
    std::cout << test.size() << std::endl;

    test2 = test;
    std::cout << test2[1][2] << std::endl;
    std::cout << test2.size() << std::endl;
}