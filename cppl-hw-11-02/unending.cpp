#include "unending.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

unending::unending() {}

unending::unending(const std::string& let)
{
	val = let;
}

unending::~unending()
{
}

unending& unending::operator = (unending&& other) noexcept
{
	std::swap(val, other.val);
	return *this;
}

unending::unending(unending&& other) noexcept : val(std::move(other.val)) {}

unending operator + (const unending& val1, const unending& val2)
{
	int len, l1 (1), l2 (1);
	if (val1.val.length() > val2.val.length())
	{
		len = val1.val.length();
		l2 = len - val2.val.length() + 1;
	}
	else
	{
		len = val2.val.length();
		l1 = len - val1.val.length() + 1;
	}
	int digit = 0;
	int ch1, ch2;
	int up = 0;
	std::string res;
	while ((len - digit) > 0)
	{
		if (val1.val.length() >= (len - digit - l1))
			ch1 = val1.val.at(len - digit - l1) - 48;
		else
			ch1 = 0;
		if (val2.val.length() >= (len - digit - l2))
			ch2 = val2.val.at(len - digit - l2) - 48;
		else
			ch2 = 0;
		res = std::to_string((up + ch1 + ch2) % 10) + res;
		up = (up + ch1 + ch2) / 10;
		++digit;
	}
	if (up) res = std::to_string(up) + res;
	return unending(res);
}

unending operator * (unending& val1, unending& val2)
{
	// Формирование hesh 
	std::vector<std::string>hesh(9);	
	for (auto i : val1.val)
	{
		if (hesh[i - 49] == "")
		{
			std::string hr ("");
			int d = 0, f = 0, e = 0, r;
			std::reverse(val2.val.begin(), val2.val.end());
			for (auto j : val2.val)
			{
				d = ((j - 48) * (i - 48)) % 10;
				r = (e + d + f) % 10;
				hr = std::to_string(r) + hr;
				f = (e + d + f) / 10;
				e = ((j - 48) * (i - 48)) / 10;
			}
			if ((e + f) % 10) hr = std::to_string((e + f) % 10) + hr;
			hesh[i - 49] = hr;
			std::reverse(val2.val.begin(), val2.val.end());
		}
	}
	// Сложение модифицированных значений их hesh
	std::string s("0");
	unending res(s);
	std::size_t dn = 0;
	std::reverse(val1.val.begin(), val1.val.end());
	for (auto i : val1.val)
	{
		std::string s1 = hesh[i - 49];
		std::string add(dn++, 48);
		s1 += add;
		unending s(s1);
		res = res + s1;
	}
	std::reverse(val1.val.begin(), val1.val.end());
	return res;
}

std::ostream& operator << (std::ostream& out, const unending& val)
{
	out << val.val;
	return out;
}