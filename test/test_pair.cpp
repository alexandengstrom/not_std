#include "../include/data_structures/pair.hpp"
#include "test_framework.hpp"

void register_pair_tests()
{
    REGISTER_TEST(pair_tests, ([&]()
                               {
    not_std::pair<int, int> p{1, 2};
    unit_test(p.first == 1, "Pair constructor and access: first element");
    unit_test(p.second == 2, "Pair constructor and access: second element"); }));

    REGISTER_TEST(pair_tests, ([&]()
                               {
    not_std::pair<int, int> original{1, 2};
    not_std::pair<int, int> copy{original};
    unit_test(copy.first == 1 && copy.second == 2, "Pair copy constructor"); }));

    REGISTER_TEST(pair_tests, ([&]()
                               {
    not_std::pair<int, int> p1{1, 2};
    not_std::pair<int, int> p2;
    p2 = p1;
    unit_test(p2.first == 1 && p2.second == 2, "Pair assignment operator"); }));

    REGISTER_TEST(pair_tests, ([&]()
                               {
    not_std::pair<int, int> p1{1, 2};
    not_std::pair<int, int> p2{1, 2};
    unit_test(p1 == p2, "Pair equality operator"); }));

    REGISTER_TEST(pair_tests, ([&]()
                               {
    not_std::pair<int, int> p1{1, 2};
    not_std::pair<int, int> p2{3, 4};
    unit_test(p1 != p2, "Pair inequality operator"); }));

    REGISTER_TEST(pair_tests, ([&]()
                               {
    not_std::pair<int, int> p1{1, 4};
    not_std::pair<int, int> p2{1, 5};
    not_std::pair<int, int> p3{2, 2};
    unit_test(p1 < p2, "Pair less than operator: comparing second element");
    unit_test(p1 < p3, "Pair less than operator: comparing first element"); }));
}
