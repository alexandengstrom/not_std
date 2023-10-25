#include "../../include/data_structures/list.hpp"
#include "../../include/data_structures/string.hpp"
#include "test_framework.hpp"

void register_list_tests()
{
    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> original;
        original.push_back(10);
        original.push_back(20);
        original.push_back(30);

        not_std::list<int> copy(original);
        unit_test(copy.front() == 10, "copy_constructor: first element should be 10");
        unit_test(copy.back() == 30, "copy_constructor: last element should be 30"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> original;
        original.push_back(10);
        original.push_back(20);
        original.push_back(30);

        not_std::list<int> assignee;
        assignee = original;
        unit_test(assignee.front() == 10, "copy_assignment: first element should be 10");
        unit_test(assignee.back() == 30, "copy_assignment: last element should be 30"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> original;
        original.push_back(10);
        original.push_back(20);
        original.push_back(30);

        not_std::list<int> moved(std::move(original));
        unit_test(moved.front() == 10, "move_constructor: first element should be 10");
        unit_test(moved.back() == 30, "move_constructor: last element should be 30");
        unit_test(original.empty(), "move_constructor: original list should be empty"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> original;
        original.push_back(10);
        original.push_back(20);
        original.push_back(30);

        not_std::list<int> assignee;
        assignee = std::move(original);
        unit_test(assignee.front() == 10, "move_assignment: first element should be 10");
        unit_test(assignee.back() == 30, "move_assignment: last element should be 30");
        unit_test(original.empty(), "move_assignment: original list should be empty"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        unit_test(lst.front() == 1, "push_back_and_access: first element should be 1");
        unit_test(lst.back() == 3, "push_back_and_access: last element should be 3"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;
        unit_test(lst.empty(), "empty: list should be empty initially");
        lst.push_back(42);
        unit_test(!lst.empty(), "empty: list should not be empty after push_back"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        unit_test(lst.size() == 3, "size: list size should be 3 after 3 push_backs"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.pop_front();
        unit_test(lst.front() == 2, "pop_front: after popping, first element should be 2"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.pop_back();
        unit_test(lst.back() == 2, "pop_back: after popping, last element should be 2"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;
        lst.push_front(1);
        lst.push_front(2);
        lst.push_front(3);
        unit_test(lst.front() == 3, "push_front: after push_front, first element should be 3"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.pop_back();
        lst.pop_back();
        lst.pop_back();
        unit_test(lst.empty(), "all_pop: list should be empty after popping all elements"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<not_std::string> lst;
        lst.push_back("Hello");
        lst.push_back("World");
        unit_test(lst.front() == "Hello", "push_back_strings: first string should be 'Hello'");
        unit_test(lst.back() == "World", "push_back_strings: second string should be 'World'"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<not_std::list<int>> lst2d;
        not_std::list<int> inner_lst;
        inner_lst.push_back(42);

        lst2d.push_back(inner_lst);
        unit_test(lst2d.front().front() == 42, "push_back_list: inner list's first element should be 42"); });

    REGISTER_TEST(list_tests, []()
                  {
        const not_std::u_int large_number = 1000000;
        not_std::list<int> lst;

        for (not_std::u_int i = 0; i < large_number; ++i)
        {
            lst.push_back(i);
        }
        unit_test(lst.size() == large_number, "stress_test: size should be 10 million after 10 million push_backs");

        for (not_std::u_int i = 0; i < large_number; ++i)
        {
            lst.pop_front();
        }
        unit_test(lst.empty(), "stress_test: list should be empty after popping 10 million times"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;

        for (int i = 0; i < 200; ++i)
        {
            lst.push_front(i);
        }

        for (int i = 0; i < 200; ++i)
        {
            unit_test(lst.back() == i, "push_front: unexpected value at back");
            lst.pop_back();
        }

        unit_test(lst.empty(), "push_front: list should be empty after operations"); });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);

        int expected_value = 1;
        for (not_std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        {
            unit_test(*it == expected_value, "iterator: expected and actual values should match");
            ++expected_value;
        }

        for (not_std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        {
            *it += 10;
        }
        
        expected_value = 11;
        for (not_std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        {
            unit_test(*it == expected_value, "iterator_modification: expected and actual values should match after modification");
            ++expected_value;
        } });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);

        int expected_value = 5;
        for (not_std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
        {
            unit_test(*rit == expected_value, "reverse_iterator: expected and actual values should match");
            --expected_value;
        } });

    REGISTER_TEST(list_tests, []()
                  {
        not_std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);

        for (not_std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
        {
            *rit += 10;
        }

        int expected_value = 15;
        for (not_std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
        {
            unit_test(*rit == expected_value, "reverse_iterator_modification: expected and actual values should match after modification");
            --expected_value;
        } });
}