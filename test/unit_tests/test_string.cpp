#include "../../include/data_structures/string.hpp"
#include "test_framework.hpp"

void register_string_tests()
{
    REGISTER_TEST(string_tests, []()
                  {
    not_std::string str("Hello");
    unit_test(str[0] == 'H', "String constructor and access: index 0");
    unit_test(str[1] == 'e', "String constructor and access: index 1");
    unit_test(str[2] == 'l', "String constructor and access: index 2");
    unit_test(str[3] == 'l', "String constructor and access: index 3");
    unit_test(str[4] == 'o', "String constructor and access: index 4"); });

    REGISTER_TEST(string_tests, []()
                  {
    not_std::string str;
    unit_test(str.length() == 0, "String length: Empty string");
    str.push_back('H');
    unit_test(str.length() == 1, "String length: Single character"); });

    REGISTER_TEST(string_tests, []()
                  {
    not_std::string str;
    for (int i{0}; i < 1000; ++i) {
        str.push_back('A' + (i % 26));
    }
    unit_test(str.length() == 1000, "String reallocations: 1000 characters"); });

    REGISTER_TEST(string_tests, []()
                  {
        not_std::string original("Hello");
        not_std::string moved(std::move(original));
        unit_test(moved == "Hello", "String move constructor: Value");
        unit_test(original.empty(), "String move constructor: Original emptied"); });

    REGISTER_TEST(string_tests, []()
                  {
        not_std::string str("Hello");
        str.clear();
        unit_test(str.empty(), "String clear: Emptiness");
        unit_test(str.length() == 0, "String clear: Length zero"); });

    REGISTER_TEST(string_tests, []()
                  {
        char long_string[1001];
        for (int i{0}; i < 1000; ++i)
        {
            long_string[i] = 'A' + (i % 26);
        }
        long_string[1000] = '\0';

        not_std::string str(long_string);
        unit_test(str.length() == 1000, "String long creation: Length"); });

    REGISTER_TEST(string_tests, []()
                  {
        not_std::string str("He\tllo\nWo\rld!");
        unit_test(str.length() == 13, "String special characters: Length");
        unit_test(str[2] == '\t', "String special characters: Tab");
        unit_test(str[6] == '\n', "String special characters: Newline"); });

    REGISTER_TEST(string_tests, []()
                  {
        not_std::string str1("Hello");
        not_std::string str2(" World!");
        str1 += str2;
        unit_test(str1 == "Hello World!", "String append strings"); });

    REGISTER_TEST(string_tests, []()
                  {
        not_std::string str("Hello");
        str.clear();
        unit_test(str.empty(), "String clear and append: After clear");
        str += "World!";
        unit_test(str == "World!", "String clear and append: After append"); });

    REGISTER_TEST(string_tests, []()
                  {
        not_std::string str("Hello");
        str = str;
        unit_test(str == "Hello", "String self assignment"); });

    REGISTER_TEST(string_tests, []()
                  {
        not_std::string str;
        for (int i{0}; i < 1000; ++i)
        {
            str.push_back('A' + (i % 26));
        }
        unit_test(str.length() == 1000, "String reallocations: 1000 characters"); });
}