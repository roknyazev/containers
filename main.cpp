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


    for (int i = 100; i >= -100; i--)
        test[i] = 0;

    ft::Map<int, int>::iterator it = test.begin();
    ft::Map<int, int>::iterator ite = test.end();

    for (; it != ite; ++it)
        std::cout << it->first << " ";
    std::cout << std::endl;
    std::cout << (test.lower_bound(95))->first << std::endl;

    std::cout << std::endl;

    std::map<int, int> test_cmp;

    for (int i = 100; i >= -100; i--)
        test_cmp[i] = 0;

    std::map<int, int>::iterator it_cmp = test_cmp.begin();
    std::map<int, int>::iterator ite_cmp = test_cmp.end();

    for (; it_cmp != ite_cmp; ++it_cmp)
        std::cout << it_cmp->first << " ";
    std::cout << std::endl;
    std::cout << (test_cmp.lower_bound(95))->first << std::endl;
	return 0;
}
