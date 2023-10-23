#include "../include/data_structures/pair.hpp"
#include <iostream>
#include <cassert>

void pair_test_constructor_and_access()
{
    not_std::pair<int, int> p{1, 2};
    assert(p.first == 1);
    assert(p.second == 2);
}

void pair_test_copy_constructor()
{
    not_std::pair<int, int> original{1, 2};
    not_std::pair<int, int> copy{original};
    assert(copy.first == 1 && copy.second == 2);
}

void pair_test_assignment_operator()
{
    not_std::pair<int, int> p1{1, 2};
    not_std::pair<int, int> p2;
    p2 = p1;
    assert(p2.first == 1 && p2.second == 2);
}

void pair_test_equality_operator()
{
    not_std::pair<int, int> p1{1, 2};
    not_std::pair<int, int> p2{1, 2};
    assert(p1 == p2);
}

void pair_test_inequality_operator()
{
    not_std::pair<int, int> p1{1, 2};
    not_std::pair<int, int> p2{3, 4};
    assert(p1 != p2);
}

void pair_test_less_than_operator()
{
    not_std::pair<int, int> p1{1, 4};
    not_std::pair<int, int> p2{1, 5};
    not_std::pair<int, int> p3{2, 2};
    assert(p1 < p2);
    assert(p1 < p3);
}

void test_pair()
{
    std::cout << "Testing not_std::pair: ";
    pair_test_constructor_and_access();
    pair_test_copy_constructor();
    pair_test_assignment_operator();
    pair_test_equality_operator();
    pair_test_inequality_operator();
    pair_test_less_than_operator();
    std::cout << "\033[32m\u2713\033[0m" << std::endl;
}
