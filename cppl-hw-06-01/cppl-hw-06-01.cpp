#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	std::string text;
	std::cout << "[IN]: ";
	getline(std::cin, text);

	int i = 0;
	char let = text[i];
	++i;
	std::map<char, int> count;
	count.emplace(let, 1);
	

	while (text[i] != '\0')
	{
		let = text[i];
		auto it = count.find(let);
		if (it != count.end()) // В этом месте проверка типа больше / меньше не работает!!!
		{
			++(it->second);
		}
		else
		{
			count.emplace(let, 1);
		}
		++i;
	}

	using data = std::pair<char, int>;
	std::vector<data> result;

	for (const auto& i : count)
	{
		result.push_back(i);
	}

	std::sort(begin(result), end(result), [](const data& a, const data& b) { return a.second > b.second; });

	for (const auto& i : result)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}
}