#include "../include/data_structures/vector.hpp"
#include <iostream>
#include <cassert>

void vector_test_push_back_and_access()
{
    not_std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    assert(vec[0] == 1);
    assert(vec[1] == 2);
    assert(vec[2] == 3);
}

void vector_test_size()
{
    not_std::vector<int> vec;
    assert(vec.size() == 0);
    vec.push_back(42);
    assert(vec.size() == 1);
}

void vector_test_empty()
{
    not_std::vector<int> vec;
    assert(vec.empty());
    vec.push_back(42);
    assert(!vec.empty());
}

void vector_test_iterator()
{
    not_std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    int sum = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        sum += *it;
    }
    assert(sum == 6);
}

void vector_test_reverse_iterator()
{
    not_std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    int product = 1;
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        product *= *it;
    }
    assert(product == 6);
}

void vector_test_clear()
{
    not_std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.clear();
    assert(vec.empty());
    assert(vec.size() == 0);
}

void vector_test_push_back_large_data()
{
    not_std::vector<int> vec;
    for (int i{0}; i < 1e6; i++)
    {
        vec.push_back(i);
    }
    assert(vec.size() == 1e6);
    assert(vec[999999] == 999999);
}

void vector_test_reallocation()
{
    not_std::vector<int> vec;
    vec.reserve(2);
    auto initial_data_ptr = &vec[0];

    vec.push_back(1);
    vec.push_back(2);
    assert(&vec[0] == initial_data_ptr);

    vec.push_back(3);
    assert(&vec[0] != initial_data_ptr);
}

void vector_test_push_back_strings()
{
    not_std::vector<std::string> vec;
    vec.push_back("Hello");
    vec.push_back("World");
    assert(vec[0] == "Hello");
    assert(vec[1] == "World");
}

void vector_test_push_back_vector()
{
    not_std::vector<not_std::vector<int>> vec2d;
    not_std::vector<int> inner_vec;
    inner_vec.push_back(42);

    vec2d.push_back(inner_vec);
    assert(vec2d[0][0] == 42);
}

void test_vector()
{
    std::cout << "Testing not_std::vector: ";
    vector_test_push_back_and_access();
    vector_test_size();
    vector_test_empty();
    vector_test_iterator();
    vector_test_reverse_iterator();
    vector_test_clear();
    vector_test_push_back_large_data();
    vector_test_reallocation();
    vector_test_push_back_strings();
    vector_test_push_back_vector();
    std::cout << "\033[32m\u2713\033[0m" << std::endl;
}
