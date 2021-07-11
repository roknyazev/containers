#include <iostream>
#include <vector>
#include "Vector.hpp"

struct test
{
	int i;
	float b;
};

int main()
{
	std::vector<float> vec;
	std::vector<float>::iterator firstIt;
	std::vector<float>::iterator lastIt;
	std::vector<float>::iterator it;

	std::cout << vec.capacity() << std::endl;
	for (int i = 0; i < 64; i++)
	{
		vec.push_back((float)i);
		std::cout << vec.capacity() << std::endl;
	}

	for (int i = 0; i < 64; i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	vec.insert(vec.begin() + 5, 1000, 0.);

	for (int i = 0; i < 1064; i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << vec.capacity() << std::endl;
	return 0;
}

//  0
//  1
//  2
//  4
//  4
//  8
//  8
//  8
//  8
//  16
//  16
//  16
//  16
//  16
//  16
//  16
//  16
//  32
//  32
//  32
//  32
//  32
//  32
//  32
//  32
//  32
//  32
//  32
//  32
//  32
//  32
//  32
//  32
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//  64
//
//  65
//
//  65
//  130
//
//  0 2 0