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

void string_test_long_creation()
{
    char long_string[1001];
    for (int i{0}; i < 1000; ++i)
    {
        long_string[i] = 'A' + (i % 26);
    }
    long_string[1000] = '\0';

    not_std::string str(long_string);
    assert(str.length() == 1000);
}

void string_test_special_characters()
{
    not_std::string str("He\tllo\nWo\rld!");
    assert(str.length() == 13);
    assert(str[2] == '\t');
    assert(str[6] == '\n');
}

void string_test_append_strings()
{
    not_std::string str1("Hello");
    not_std::string str2(" World!");

    str1 += str2;
    assert(str1 == "Hello World!");
}

void string_test_clear_and_append()
{
    not_std::string str("Hello");
    str.clear();
    assert(str.empty());
    str += "World!";
    assert(str == "World!");
}

void string_test_self_assignment()
{
    not_std::string str("Hello");
    str = str;
    assert(str == "Hello");
}

void string_test_reallocations()
{
    not_std::string str;
    for (int i{0}; i < 1000; ++i)
    {
        str.push_back('A' + (i % 26));
    }
    assert(str.length() == 1000);
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
    string_test_long_creation();
    string_test_special_characters();
    string_test_append_strings();
    string_test_clear_and_append();
    string_test_self_assignment();
    string_test_reallocations();
    std::cout << "\033[32m\u2713\033[0m" << std::endl;
}
