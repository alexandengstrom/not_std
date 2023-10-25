#include "test_framework.hpp"
#include <unordered_map>
#include "../../include/data_structures/unordered_map.hpp"
#include "../../include/data_structures/string.hpp" // Assuming this is where not_std::string is defined.
#include <iostream>

// 1. Benchmark for not_std::unordered_map
void benchmark_not_std_unordered_map(int NUM_ELEMENTS)
{
    not_std::unordered_map<not_std::string, int> umap;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        umap.insert(not_std::string("key") + std::to_string(i), i);
    }

    for (int i = 0; i < NUM_ELEMENTS / 2; ++i)
    {
        int v = umap[not_std::string("key") + std::to_string(i)];
    }

    for (auto it{umap.begin()}; it != umap.end(); ++it)
    {
        auto [k, v] = *it;
    }
}

// 2. Benchmark for std::unordered_map
void benchmark_std_unordered_map(int NUM_ELEMENTS)
{
    std::unordered_map<std::string, int> umap;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        umap.insert({std::string("key") + std::to_string(i), i});
    }

    for (int i = 0; i < NUM_ELEMENTS / 2; ++i)
    {
        int v = umap[std::string("key") + std::to_string(i)];
    }

    for (auto it{umap.begin()}; it != umap.end(); ++it)
    {
        auto [k, v] = *it;
    }
}

void unordered_map_small_test()
{
    compare_benchmarks(
        "unordered_map",
        [&]()
        { benchmark_not_std_unordered_map(10000); },
        [&]()
        { benchmark_std_unordered_map(10000); },
        100000);
}

void unordered_map_big_test()
{
    compare_benchmarks(
        "unordered_map",
        [&]()
        { benchmark_not_std_unordered_map(1000000); },
        [&]()
        { benchmark_std_unordered_map(1000000); },
        10000000);
}

void register_unordered_map_test()
{
    unordered_map_small_test();
    unordered_map_big_test();
}
