#include "../../include/data_structures/set.hpp"
#include "test_framework.hpp"
#include <vector>
#include <algorithm>

void register_set_tests()
{
    REGISTER_TEST(set_tests, []()
                  {
        not_std::set<int> s;
        s.insert(1);
        s.insert(2);
        s.insert(3);
        unit_test(s.contains(1), "insert_and_check: set should contain the number 1");
        unit_test(s.contains(2), "insert_and_check: set should contain the number 2");
        unit_test(s.contains(3), "insert_and_check: set should contain the number 3"); });

    REGISTER_TEST(set_tests, []()
                  {
        not_std::set<int> s;
        unit_test(s.size() == 0, "size: set size should be 0 initially");
        s.insert(42);
        unit_test(s.size() == 1, "size: set size should be 1 after insert");
        s.erase(42);
        unit_test(s.size() == 0, "erase: set size should be 0 after erase"); });

    REGISTER_TEST(set_tests, []()
                  {
        not_std::set<int> s;
        unit_test(s.empty(), "empty: set should be empty initially");
        s.insert(58);
        unit_test(!s.empty(), "empty: set should not be empty after insert"); });

    REGISTER_TEST(set_tests, []()
                  {
        not_std::set<int> s;
        s.insert(100);
        s.insert(100);
        s.insert(100);
        unit_test(s.size() == 1, "insert_same_value: set size should remain 1 after inserting the same value multiple times"); });

    REGISTER_TEST(set_tests, []()
                  {
        not_std::set<int> s;
        s.insert(200);
        s.erase(201);
        unit_test(s.size() == 1, "erase_non_existent_value: set size should remain unchanged when erasing non-existent value"); });

    REGISTER_TEST(set_tests, []()
                  {
        not_std::set<int> set;

        for (int i{0}; i < 1000; ++i) 
        {
            int random_val = rand() % 10000;
            set.insert(random_val);
        }

        int prev{-1};
        for (auto it{set.begin()}; it != set.end(); ++it) {
            unit_test(*it > prev, "checking order in iterator: next value should always be greater then previous");
            prev = *it;
        } });

    REGISTER_TEST(set_tests, []()
                  {
        not_std::set<int> set;

        for (int i{0}; i < 1000; ++i) 
        {
            int random_val = rand() % 10000;
            set.insert(random_val);
        }

        int prev{10001};
        for (auto it{set.rbegin()}; it != set.rend(); ++it) {
            unit_test(*it < prev, "checking order in reverse iterator: next value should always be less then previous");
            prev = *it;
        } });
}
