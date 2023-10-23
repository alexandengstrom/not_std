#include "../include/data_structures/string.hpp"
#include <iostream>
#include <cassert>

void string_test_constructor_and_access()
{
    not_std::string str("Hello");
    assert(str[0] == 'H');
    assert(str[1] == 'e');
    assert(str[2] == 'l');
    assert(str[3] == 'l');
    assert(str[4] == 'o');
}

void string_test_length()
{
    not_std::string str;
    assert(str.length() == 0);
    str.push_back('H');
    assert(str.length() == 1);
}

void string_test_empty()
{
    not_std::string str;
    assert(str.empty());
    str.push_back('H');
    assert(!str.empty());
}

void string_test_copy_constructor()
{
    not_std::string original("Hello");
    not_std::string copy(original);
    assert(copy == "Hello");
}

void string_test_move_constructor()
{
    not_std::string original("Hello");
    not_std::string moved(std::move(original));
    assert(moved == "Hello");
    assert(original.empty());
}

void string_test_clear()
{
    not_std::string str("Hello");
    str.clear();
    assert(str.empty());
    assert(str.length() == 0);
}

void test_string()
{
    std::cout << "Testing not_std::string: ";
    string_test_constructor_and_access();
    string_test_length();
    string_test_empty();
    string_test_copy_constructor();
    string_test_move_constructor();
    string_test_clear();
    std::cout << "\033[32m\u2713\033[0m" << std::endl;
}
