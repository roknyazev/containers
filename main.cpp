#include <iostream>
#include <vector>
#include "Vector.hpp"
#include <ctime>
#include "AVL.hpp"
#include <map>
#include "MapIterator.hpp"
#include <vector>
#include "Map.hpp"

int main()
{
	std::map<int, int> test;
	std::map<int, int>::iterator it = test.begin();
    std::map<int, int>::iterator ite = test.end();


    std::cout << it->first << std::endl;

	return 0;//&(*test.begin()) == &(*test.end());
}
