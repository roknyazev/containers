#include <iostream>
#include <vector>
#include "Vector.hpp"
#include <ctime>

struct test
{
	int i;
	float b;
};

int main()
{
	size_t cl = clock();

	ft::Vector<double> vec;
	ft::Vector<double>::iterator firstIt;
	ft::Vector<double>::iterator lastIt;
	ft::Vector<double>::iterator it;

	std::cout << vec.capacity() << std::endl;

	int tmp1 = 6500000;
	int tmp2 = 4000000;

	for (int i = 0; i < tmp1; i++)
	{
		vec.insert(vec.end(), i);
		std::cout << vec.capacity() << "    ";
		std::cout << vec.size() << std::endl;
	}

	std::cout << "    " << vec.size() << std::endl;
	vec.insert(vec.begin() + 10, tmp2, 0);
	std::cout << "    " << vec.size() << std::endl;

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	vec.erase(vec.begin() + 5, vec.begin() + 20);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	vec.resize(10);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << vec.capacity() << std::endl;
	std::cout << std::endl;
	std::cout << (clock() - cl) / (double)CLOCKS_PER_SEC << std::endl;
	return 0;
}
