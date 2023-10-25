#include "test_framework.hpp"
#include <list>
#include "../../include/data_structures/list.hpp"

void benchmark_not_std_list(int NUM_ELEMENTS)
{
    not_std::list<int> lst;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        lst.push_back(i);

        if (i % 2 == 0)
        {
            lst.front();
        }
        else
        {
            lst.back();
        }

        lst.size();
    }

    for (auto it{lst.begin()}; it != lst.end(); ++it)
    {
        int v = *it;
    }
}

void benchmark_std_list(int NUM_ELEMENTS)
{
    std::list<int> lst;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        lst.push_back(i);

        if (i % 2 == 0)
        {
            lst.front();
        }
        else
        {
            lst.back();
        }

        lst.size();
    }

    for (auto it{lst.begin()}; it != lst.end(); ++it)
    {
        int v = *it;
    }
}

void list_small_test()
{
    compare_benchmarks(
        "list",
        [&]()
        { benchmark_not_std_list(100000); },
        [&]()
        { benchmark_std_list(100000); },
        100000);
}

void list_big_test()
{
    compare_benchmarks(
        "list",
        [&]()
        { benchmark_not_std_list(10000000); },
        [&]()
        { benchmark_std_list(10000000); },
        10000000);
}

void register_list_test()
{
    list_small_test();
    list_big_test();
}
