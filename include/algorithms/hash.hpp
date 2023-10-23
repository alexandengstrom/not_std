#ifndef HASH_HPP
#define HASH_HPP

// #include <string>
#include "../common/common_defs.hpp"

namespace not_std
{

    template <typename T>
    struct hash;

    template <>
    struct hash<int>
    {
        lu_int operator()(const int &key) const
        {
            lu_int hash_value = key;
            hash_value = (hash_value ^ (hash_value >> 16)) * 0x85ebca6b;
            hash_value = hash_value ^ (hash_value >> 13);
            hash_value = (hash_value * 0xc2b2ae35) ^ (hash_value >> 16);
            return hash_value;
        }
    };

    template <>
    struct hash<unsigned int>
    {
        lu_int operator()(const unsigned int &key) const
        {
            lu_int hash_value = key;
            hash_value = (hash_value ^ (hash_value >> 16)) * 0x85ebca6b;
            hash_value = hash_value ^ (hash_value >> 13);
            hash_value = (hash_value * 0xc2b2ae35) ^ (hash_value >> 16);
            return hash_value;
        }
    };

    template <>
    struct hash<long int>
    {
        lu_int operator()(const long int &key) const
        {
            lu_int hash_value = key;
            hash_value = (hash_value ^ (hash_value >> 16)) * 0x85ebca6b;
            hash_value = hash_value ^ (hash_value >> 13);
            hash_value = (hash_value * 0xc2b2ae35) ^ (hash_value >> 16);
            return hash_value;
        }
    };

}

#endif