#include <iostream>
#include "stack.hpp"
#include <stack>

int main()
{
    size_t cl;
    int tmp1 = 650000;

    std::cout << "ft::stack" << std::endl;
    ft::stack<double> stack;
    cl = clock();
    for (int i = 0; i < tmp1; i++)
    {
        stack.push(4);
    }
    std::cout << stack.size() << std::endl;
    std::cout << stack.top() << std::endl;
    for (int i = 0; i < tmp1; i++)
    {
        stack.pop();
    }
    std::cout << stack.size() << std::endl;
    std::cout << (clock() - cl) / (double)CLOCKS_PER_SEC << std::endl;


    std::cout << std::endl;
    std::cout << "std::stack" << std::endl;
    std::stack<double> stack_cmp;
    cl = clock();
    for (int i = 0; i < tmp1; i++)
    {
        stack_cmp.push(4);
    }
    std::cout << stack_cmp.size() << std::endl;
    std::cout << stack_cmp.top() << std::endl;
    for (int i = 0; i < tmp1; i++)
    {
        stack_cmp.pop();
    }
    std::cout << stack_cmp.size() << std::endl;
    std::cout << (clock() - cl) / (double)CLOCKS_PER_SEC << std::endl;
    return 0;
}

