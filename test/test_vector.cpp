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
    for (auto it = vec.rbegin(); it != vec.rend(); --it)
    {
        product *= *it;
    }
    assert(product == 6);
}

void vector_test_const_reverse_iterator()
{
    not_std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    int product = 1;
    for (auto it = vec.crbegin(); it != vec.crend(); --it)
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

void test_vector()
{
    std::cout << "Testing not_std::vector: ";
    vector_test_push_back_and_access();
    vector_test_size();
    vector_test_empty();
    vector_test_iterator();
    vector_test_reverse_iterator();
    vector_test_const_reverse_iterator();
    vector_test_clear();
    std::cout << "\033[32m\u2713\033[0m" << std::endl;
}
