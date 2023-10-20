#include "../include/not_std/vector.hpp"
#include <iostream>
#include <cassert>

void test_push_back_and_access()
{
    not_std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    assert(vec[0] == 1);
    assert(vec[1] == 2);
    assert(vec[2] == 3);
    std::cout << "Test 1 passed" << std::endl;
}

void test_size()
{
    not_std::vector<int> vec;
    assert(vec.size() == 0);
    vec.push_back(42);
    assert(vec.size() == 1);
    std::cout << "Test 2 passed" << std::endl;
}

void test_empty()
{
    not_std::vector<int> vec;
    assert(vec.empty());
    vec.push_back(42);
    assert(!vec.empty());
    std::cout << "Test 3 passed" << std::endl;
}

void test_iterator()
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
    std::cout << "Test 4 passed" << std::endl;
}

void test_reverse_iterator()
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
    std::cout << "Test 5 passed" << std::endl;
}

void test_const_reverse_iterator()
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
    std::cout << "Test 6 passed" << std::endl;
}

void test_clear()
{
    not_std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.clear();
    assert(vec.empty());
    assert(vec.size() == 0);
    std::cout << "Test 7 passed" << std::endl;
}

int main()
{
    test_push_back_and_access();
    test_size();
    test_empty();
    test_iterator();
    test_reverse_iterator();
    test_const_reverse_iterator();
    test_clear();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
