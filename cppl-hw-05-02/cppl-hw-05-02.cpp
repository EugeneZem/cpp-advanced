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

    table& operator = (table rpar)
    {
        T** new_arr = new T * [this._col];
        for (int a = 0; a < this._col; ++a)
        {
            new_arr[a] = new T[this._row];
        }
        for (int a = 0; a < this._col; ++a)
        {
            for (int b = 0; b < this._row; ++b)
            {
                new_arr[a][b] = this[a][b];
            }
        }
        return &new_arr;
    }

    const T& operator [] (int i) const
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

private:
    T** arr = nullptr;
    const int _col, _row;
};

int main()
{
    auto test = table<int>(2, 3);
    test[1][0] = 4;
    std::cout << test[1][0] << std::endl;
    std::cout << test.size() << std::endl;

    auto test2 = test;
    std::cout << test2[1][0] << std::endl;
    std::cout << test2.size() << std::endl;
}