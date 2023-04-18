#include <iostream>
#include "BloomFilter copy.hpp"

using namespace std;

int main()
{
    BloomFilter<int> int_filter;

    // Add some values to the filter
    cout << "Add: 42" << endl;
    int_filter.Add(42);
    int_filter.Print();
    cout << "Add: 89" << endl;
    int_filter.Add(89);
    int_filter.Print();

    // Check if values are contained in the filter
    cout << "Contains 42: " << int_filter.Contains(42) << endl;
    cout << "Contains 54: " << int_filter.Contains(54) << endl;
    cout << "Contains 53: " << int_filter.Contains(53) << endl;

    BloomFilter<char *> string_filter;

    char *s1 = "Horse";
    char *s2 = "Frog";
    char *s3 = "Girraffe";

    // Add some values to the filter
    cout << "Add: Horse" << endl;
    string_filter.Add(s1);
    string_filter.Print();
    cout << "Add: Frog" << endl;
    string_filter.Add(s2);
    string_filter.Print();

    // Check if values are contained in the filter
    cout << "Contains Horse: " << string_filter.Contains(s1) << endl;
    cout << "Contains Girraffe: " << string_filter.Contains(s3) << endl;

    return 0;
}
