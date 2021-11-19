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



    test[5] = 5;
    it = test.begin();
    std::cout << it->first << std::endl;



    test[2] = 2;

    test[3] = 3;

    test[7] = 7;

    it = test.begin();
    std::cout << it->first << std::endl;

    for (; it != ite; ++it)
        std::cout << it->first << " ";
    std::cout << std::endl;


    std::cout << std::endl;
    std::map<int, int> test_cmp;
    std::map<int, int>::iterator it_cmp = test_cmp.begin();
    std::map<int, int>::iterator ite_cmp = test_cmp.end();



    test_cmp[5] = 5;
    it_cmp = test_cmp.begin();
    std::cout << it_cmp->first << std::endl;

    test_cmp[2] = 2;

    test_cmp[3] = 3;

    test_cmp[7] = 7;

    it_cmp = test_cmp.begin();
    std::cout << it_cmp->first << std::endl;


    for (; it_cmp != ite_cmp; ++it_cmp)
        std::cout << it_cmp->first << " ";
    std::cout << std::endl;
	return 0;
}
