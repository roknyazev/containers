#include <iostream>
#include <map>
#include "map.hpp"


int main()
{
    size_t cl;

    std::cout << "ft::map" << std::endl;
	ft::map<int, int> map;

    cl = clock();
    for (int i = 100; i >= -100; i--)
        map[i] = 0;

    ft::map<int, int>::iterator it = map.begin();
    ft::map<int, int>::iterator ite = map.end();

    for (; it != ite; ++it)
        std::cout << it->first << " ";
    for (int i = 100000; i >= -100; i--)
        map[i] = 0;
    std::cout << std::endl;
    std::cout << (map.lower_bound(95))->first << std::endl;
    std::cout << (map.upper_bound(95))->first << std::endl;
    std::cout << map.size() << std::endl;
    std::cout << (clock() - cl) / (double)CLOCKS_PER_SEC << std::endl;



    std::cout << std::endl;
    std::cout << "std::map" << std::endl;
    std::map<int, int> map_cmp;

    cl = clock();
    for (int i = 100; i >= -100; i--)
        map_cmp[i] = 0;

    std::map<int, int>::iterator it_cmp = map_cmp.begin();
    std::map<int, int>::iterator ite_cmp = map_cmp.end();

    for (; it_cmp != ite_cmp; ++it_cmp)
        std::cout << it_cmp->first << " ";
    for (int i = 100000; i >= -100; i--)
        map_cmp[i] = 0;
    std::cout << std::endl;
    std::cout << (map_cmp.lower_bound(95))->first << std::endl;
    std::cout << (map_cmp.upper_bound(95))->first << std::endl;
    std::cout << map_cmp.size() << std::endl;
    std::cout << (clock() - cl) / (double)CLOCKS_PER_SEC << std::endl;
	return 0;
}
