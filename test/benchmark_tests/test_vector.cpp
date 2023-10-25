#include "test_framework.hpp"
#include <vector>
#include "../../include/data_structures/vector.hpp"

void benchmark_not_std_vector(int NUM_ELEMENTS)
{
    not_std::vector<int> vec;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.push_back(i);
        int access_index = i / 2;
        int val = vec[access_index];
    }

    for (auto it{vec.begin()}; it != vec.end(); ++it)
    {
        int v = *it;
    }
}

void benchmark_std_vector(int NUM_ELEMENTS)
{
    std::vector<int> vec;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.push_back(i);
        int access_index = i / 2;
        int val = vec[access_index];
    }

    for (auto it{vec.begin()}; it != vec.end(); ++it)
    {
        int v = *it;
    }
}

void vector_small_test()
{
    compare_benchmarks(
        "vector",
        [&]()
        { benchmark_not_std_vector(100000); },
        [&]()
        { benchmark_std_vector(100000); },
        100000);
}

void vector_big_test()
{
    compare_benchmarks(
        "vector",
        [&]()
        { benchmark_not_std_vector(10000000); },
        [&]()
        { benchmark_std_vector(10000000); },
        10000000);
}

void register_vector_test()
{
    vector_small_test();
    vector_big_test();
}
