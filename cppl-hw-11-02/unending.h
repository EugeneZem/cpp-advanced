#pragma once
#include <string>
#include <iostream>

class unending
{
public:
	unending();

	unending(const std::string&);

	~unending();

	unending(unending&&) noexcept;

	unending(const unending&);

	unending& operator = (unending&) noexcept;

	unending& operator = (unending&& other) noexcept;

	friend unending operator + (const unending&, const unending&);

	friend unending operator * (unending&, unending&);

	friend std::ostream& operator << (std::ostream& , const unending&);

private:
	std::string val;
};
