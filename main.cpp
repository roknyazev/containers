#include <iostream>
#include <vector>

struct test
{
	int i;
};

int main()
{
	std::vector<int> vec;
	std::vector<int>::iterator firstIt;
	std::vector<int>::iterator lastIt;
	std::vector<int>::iterator it;

	std::cout << vec.capacity() << std::endl;
	for (int i = 0; i < 64; i++)
	{
		vec.push_back(i);
		std::cout << vec.capacity() << std::endl;
	}

	std::cout << std::endl;
	vec.reserve(65);
	std::cout << vec.capacity() << std::endl;
	std::cout << std::endl;

	vec.push_back(7);
	std::cout << vec.capacity() << std::endl;
	vec.push_back(7);
	std::cout << vec.capacity() << std::endl;



	firstIt = vec.begin();
	lastIt = vec.end();

	it = firstIt;
	std::cout << std::endl << *it << " " <<  *(it + 2) << " " << *it << std::endl;
	return 0;
}
