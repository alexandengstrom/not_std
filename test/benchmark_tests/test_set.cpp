#include "test_framework.hpp"
#include <set>
#include "../../include/data_structures/set.hpp"

void benchmark_not_std_set(int NUM_ELEMENTS)
{
    not_std::set<int> s;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        s.insert(i);

        if (i % 2 == 0)
        {
            s.contains(i);
        }
        else if (i % 3 == 0)
        {
            s.erase(i);
            s.insert(i);
        }
        else if (i % 5 == 0)
        {
            s.erase(i / 2);
        }

        if (i % 11 == 0)
        {
            s.insert(i % 49);
        }
    }

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        int v = *it;
    }
}

void benchmark_std_set(int NUM_ELEMENTS)
{
    std::set<int> s;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        s.insert(i);

        if (i % 2 == 0)
        {
            s.count(i);
        }
        else if (i % 3 == 0)
        {
            s.erase(i);
            s.insert(i);
        }
        else if (i % 5 == 0)
        {
            s.erase(i / 2);
        }

        if (i % 11 == 0)
        {
            s.insert(i % 49);
        }
    }

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        int v = *it;
    }
}

void set_small_test()
{
    compare_benchmarks(
        "set",
        [&]()
        { benchmark_not_std_set(100000); },
        [&]()
        { benchmark_std_set(100000); },
        100000);
}

void set_big_test()
{
    compare_benchmarks(
        "set",
        [&]()
        { benchmark_not_std_set(10000000); },
        [&]()
        { benchmark_std_set(10000000); },
        10000000);
}

void register_set_test()
{
    set_small_test();
    set_big_test();
}
