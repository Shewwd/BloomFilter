/*

    This Bloom filter will have 3 hash function  that support float, int, strings, & chars
    Bit-Array size 10

*/

#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP

#include <cstddef>

using namespace std;

template <size_t N>
class Bitset
{
public:
    Bitset() : data_{0} {}

    void Set(size_t pos, bool value)
    {
        if (value)
        {
            data_[pos / 8] |= (1 << (pos % 8));
        }
        else
        {
            data_[pos / 8] &= ~(1 << (pos % 8));
        }
    }

    bool Test(size_t pos) const
    {
        return (data_[pos / 8] & (1 << (pos % 8))) != 0;
    }

private:
    unsigned char data_[(N + 7) / 8]{};
};

class BloomFilter
{
public:
    BloomFilter() = default;

    void Add(float value)
    {
        AddHash(HashValue(value));
    }

    void Add(int value)
    {
        AddHash(HashValue(value));
    }

    void Add(const char *value)
    {
        AddHash(HashValue(value));
    }

    void Add(char value)
    {
        AddHash(HashValue(value));
    }

    bool Contains(float value) const
    {
        return ContainsHash(HashValue(value));
    }

    bool Contains(int value) const
    {
        return ContainsHash(HashValue(value));
    }

    bool Contains(const char *value) const
    {
        return ContainsHash(HashValue(value));
    }

    bool Contains(char value) const
    {
        return ContainsHash(HashValue(value));
    }

private:
    Bitset<10> bit_array;

    void AddHash(size_t hash_value)
    {
        for (int i = 0; i < 3; ++i)
        {
            bit_array.Set(hash_value % 10, true);
            hash_value = hash_value * 37 + i;
        }
    }

    bool ContainsHash(size_t hash_value) const
    {
        for (int i = 0; i < 3; ++i)
        {
            if (!bit_array.Test(hash_value % 10))
            {
                return false;
            }
            hash_value = hash_value * 37 + i;
        }
        return true;
    }

    size_t HashValue(int value) const
    {
        return static_cast<size_t>(value);
    }

    size_t HashValue(float value) const
    {
        return static_cast<size_t>(*reinterpret_cast<int *>(&value));
    }

    size_t HashValue(const char *value) const
    {
        size_t hash = 5381;
        while (*value != '\0')
        {
            hash = ((hash << 5) + hash) + *value++;
        }
        return hash;
    }

    size_t HashValue(char value) const
    {
        return static_cast<size_t>(value);
    }
};

#endif // BLOOM_FILTER_HPP
