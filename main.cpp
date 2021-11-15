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
	ft::Map<int, int> test;
	ft::Map<int, int>::iterator it = test.begin();
    ft::Map<int, int>::iterator ite = test.end();


    std::cout << it->first << std::endl;
    test[5] = 5;
    std::cout << it->first << std::endl;
	return 0;
}
