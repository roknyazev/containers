#include <iostream>
#include "vector.hpp"
#include <vector>


int main()
{
    size_t cl;
    int tmp1 = 650000;
    int tmp2 = 400000;

    std::cout << "ft::vector" << std::endl;
    ft::vector<double> vec;
    cl = clock();
    for (int i = 0; i < tmp1; i++)
    {
        vec.insert(vec.end(), i);
    }
    std::cout  << vec.size() << std::endl;
    vec.insert(vec.begin() + 10, tmp2, 0);
    std::cout  << vec.size() << std::endl;
    vec.erase(vec.begin() + 5, vec.begin() + 20);
    vec.resize(10);
    std::cout << (clock() - cl) / (double)CLOCKS_PER_SEC << std::endl;


    std::cout << std::endl;
    std::cout << "std::vector" << std::endl;
    std::vector<double> vec_cmp;
    cl = clock();
    for (int i = 0; i < tmp1; i++)
    {
        vec_cmp.insert(vec_cmp.end(), i);
    }
    std::cout  << vec_cmp.size() << std::endl;
    vec_cmp.insert(vec_cmp.begin() + 10, tmp2, 0);
    std::cout  << vec_cmp.size() << std::endl;
    vec_cmp.erase(vec_cmp.begin() + 5, vec_cmp.begin() + 20);
    vec_cmp.resize(10);
    std::cout << (clock() - cl) / (double)CLOCKS_PER_SEC << std::endl;
    return 0;
}