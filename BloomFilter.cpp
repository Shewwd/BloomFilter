#include <iostream>
#include "BloomFilter.hpp"

using namespace std;

int main()
{
    BloomFilter filter;

    // Add some values to the filter
    filter.Add(42);
    filter.Add(3.14f);
    filter.Add("hello");
    filter.Add('c');

    // Check if values are contained in the filter
    std::cout << "Contains 42: " << filter.Contains(42) << std::endl;
    std::cout << "Contains 3.14f: " << filter.Contains(3.14f) << std::endl;
    std::cout << "Contains \"hello\": " << filter.Contains("hello") << std::endl;
    std::cout << "Contains 'c': " << filter.Contains('c') << std::endl;
    std::cout << "Contains 'l': " << filter.Contains('l') << std::endl;

    return 0;
}
