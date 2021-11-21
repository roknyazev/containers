
#include <iostream>
#include <map>
#include <vector>
#include <stack>

int main()
{
    size_t cl;

    std::cout << std::endl;
    std::cout << "map" << std::endl;
    std::map<int, int> map;

    cl = clock();
    for (int i = 100; i >= -100; i--)
        map[i] = 0;

    std::map<int, int>::iterator it = map.begin();
    std::map<int, int>::iterator ite = map.end();

    for (; it != ite; ++it)
        std::cout << it->first << " ";
    for (int i = 100000; i >= -100; i--)
        map[i] = 0;
    std::cout << std::endl;
    std::cout << (map.lower_bound(95))->first << std::endl;
    std::cout << (map.upper_bound(95))->first << std::endl;
    std::cout << map.size() << std::endl;
    std::cout << (clock() - cl) / (double)CLOCKS_PER_SEC << std::endl;


    int tmp1 = 650000;
    int tmp2 = 400000;

    std::cout << std::endl;
    std::cout << "vector" << std::endl;
    std::vector<double> vec;
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
    std::cout << "stack" << std::endl;
    std::stack<double> stack;
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

    return 0;
}