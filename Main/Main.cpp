#include <iostream>

#include "Array/Array.h"

int main(int argc, char* argv[])
{
    Array<int> i;

    i.push_back(1);
    i.push_back(2);
    i.push_back(3);
    i.push_back(4);
    i.push_back(5);

    for (size_t x = 0; x < i.size(); x++)
    {
        std::cout << i[x] << '\n';
    }

    std::cout << "-------------------------------------" << '\n';

    i.resize(10);
    
    for (size_t x = 0; x < i.size(); x++)
    {
        std::cout << i[x] << '\n';
    }

    std::cout << "-------------------------------------" << '\n';

    i.resize(15, 1234567890);
    
    for (size_t x = 0; x < i.size(); x++)
    {
        std::cout << i[x] << '\n';
    }
    
    return 0;
}
