#include "test_framework.hpp"
#include <bitset>
#include "../../include/data_structures/bitset.hpp"

void benchmark_not_std_bitset_small()
{
    constexpr int NUM_BITS = 100000;
    not_std::bitset<NUM_BITS> bs;
    for (int i = 0; i < NUM_BITS; ++i)
    {
        bs.set(i);
        bool bit = bs[i];
    }

    for (u_int i = 0; i < NUM_BITS; i += 2)
    {
        bs.flip(i);
    }
}

void benchmark_not_std_bitset_big()
{
    constexpr int NUM_BITS = 10000000;
    not_std::bitset<NUM_BITS> bs;
    for (int i = 0; i < NUM_BITS; ++i)
    {
        bs.set(i);
        bool bit = bs[i];
    }

    for (u_int i = 0; i < NUM_BITS; i += 2)
    {
        bs.flip(i);
    }
}

void benchmark_std_bitset_small()
{
    constexpr int NUM_BITS = 100000;
    std::bitset<NUM_BITS> bs;
    for (int i = 0; i < NUM_BITS; ++i)
    {
        bs.set(i);
        bool bit = bs[i];
    }

    for (u_int i = 0; i < NUM_BITS; i += 2)
    {
        bs.flip(i);
    }
}

void benchmark_std_bitset_big()
{
    constexpr int NUM_BITS = 10000000;
    std::bitset<NUM_BITS> bs;
    for (int i = 0; i < NUM_BITS; ++i)
    {
        bs.set(i);
        bool bit = bs[i];
    }

    for (u_int i = 0; i < NUM_BITS; i += 2)
    {
        bs.flip(i);
    }
}

void bitset_small_test()
{
    compare_benchmarks(
        "bitset",
        [&]()
        { benchmark_not_std_bitset_small(); },
        [&]()
        { benchmark_std_bitset_small(); },
        100000);
}

void bitset_big_test()
{
    compare_benchmarks(
        "bitset",
        [&]()
        { benchmark_not_std_bitset_big(); },
        [&]()
        { benchmark_std_bitset_big(); },
        10000000);
}

void register_bitset_test()
{
    bitset_small_test();
    bitset_big_test();
}
