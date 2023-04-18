/*

    This Bloom filter will have 3 hash function  that support float, int, char *, & chars
    Bit-Array size 10

*/

#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP

#include <iostream>

using namespace std;

template <int N>
class BitArray
{
public:
    BitArray()
    {
        for (int i = 0; i < N; i++)
        {
            array[i] = 0;
        }
    }

    void Set(int pos)
    {
        array[pos] = 1;
    }

    bool Test(int pos)
    {
        return array[pos];
    }

    int &operator[](int index)
    {
        return this->array[index];
    }

private:
    int array[10];
};

template <typename T>
class BloomFilter
{
public:
    void Add(T data)
    {
        int h1 = H1(data);
        bit_array.Set(h1);
        int h2 = H2(data);
        bit_array.Set(h2);
        int h3 = H3(data);
        bit_array.Set(h3);
    }

    bool Contains(T data)
    {
        int h1 = H1(data);
        if (!bit_array.Test(h1))
            return false;
        int h2 = H2(data);
        if (!bit_array.Test(h2))
            return false;
        int h3 = H3(data);
        if (!bit_array.Test(h3))
            return false;

        return true;
    }

    void Print()
    {
        for (int i = 0; i < 10; ++i)
        {
            cout << bit_array[i] << " ";
        }
        cout << endl;
    }

private:
    BitArray<10> bit_array;

    int H1(int data)
    {
        int value = (data + 12) + (data + 12);
        cout << "H1: " << value << " % 10 = " << value % 10 << ", ";
        return value % 10;
    }

    int H1(float data)
    {
        int value = (data + 12) + (data + 12);
        return (int)value % 10;
    }

    int H1(char data)
    {
        int value = (int)data;
        value = (value + 12) + (value + 12);
        return value % 10;
    }

    int H1(char *data)
    {
        int value = atoi(data);
        value = (value + 12) + (value + 12);
        return value % 10;
    }

    int H2(int data)
    {
        int value = (value * 19) * (value * 19);
        cout << "H2: " << value << " % 10 = " << value % 10 << ", ";
        return value % 10;
    }

    int H2(float data)
    {
        int value = (value * 19) * (value * 19);
        return (int)value % 10;
    }

    int H2(char data)
    {
        int value = (int)data;
        value = (value * 19) * (value * 19);
        return value % 10;
    }

    int H2(char *data)
    {
        int value = atoi(data);
        value = (value * 19) * (value * 19);
        return value % 10;
    }

    int H3(int data)
    {
        int value = (value + 3) + (value + 3);
        cout << "H3: " << value << " % 10 = " << value % 10 << ", ";
        cout << endl;
        return value % 10;
    }

    int H3(float data)
    {
        int value = (value + 3) + (value + 3);
        return (int)value % 10;
    }

    int H3(char data)
    {
        int value = (int)data;
        value = (value + 3) + (value + 3);
        return value % 10;
    }

    int H3(char *data)
    {
        int value = atoi(data);
        value = (value + 3) + (value + 3);
        return value % 10;
    }
};

#endif // BLOOM_FILTER_HPP
