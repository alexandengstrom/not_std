#include "test_framework.hpp"
#include <string>
#include "../../include/data_structures/string.hpp"

void benchmark_not_std_string(int NUM_OPERATIONS)
{
    not_std::string str;

    for (int i = 0; i < NUM_OPERATIONS; ++i)
    {
        not_std::string tmp{"space"};
        str += "Hello";
        str += tmp;
        str += "World";
        str.length();
        str.clear();
    }
}

void benchmark_std_string(int NUM_OPERATIONS)
{
    std::string str;

    for (int i = 0; i < NUM_OPERATIONS; ++i)
    {
        std::string tmp{"space"};
        str += "Hello";
        str += tmp;
        str += "World";
        str.length();
        str.clear();
    }
}

void string_small_test()
{
    compare_benchmarks(
        "string",
        [&]()
        { benchmark_not_std_string(100000); },
        [&]()
        { benchmark_std_string(100000); },
        100000);
}

void string_big_test()
{
    compare_benchmarks(
        "string",
        [&]()
        { benchmark_not_std_string(10000000); },
        [&]()
        { benchmark_std_string(10000000); },
        10000000);
}

void register_string_test()
{
    string_small_test();
    string_big_test();
}
