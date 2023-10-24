#include "../include/data_structures/vector.hpp"
// #include "../include/data_structures/string.hpp"
#include "test_framework.hpp"

void register_vector_tests()
{
    REGISTER_TEST(vector_tests, []()
                  {
        not_std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        unit_test(vec[0] == 1, "push_back_and_access: first element should be 1");
        unit_test(vec[1] == 2, "push_back_and_access: second element should be 2");
        unit_test(vec[2] == 3, "push_back_and_access: third element should be 3"); });

    REGISTER_TEST(vector_tests, []()
                  {
        not_std::vector<int> vec;
        unit_test(vec.size() == 0, "size: vector size should be 0 initially");
        vec.push_back(42);
        unit_test(vec.size() == 1, "size: vector size should be 1 after push_back"); });

    REGISTER_TEST(vector_tests, []()
                  {
        not_std::vector<int> vec;
        unit_test(vec.empty(), "empty: vector should be empty initially");
        vec.push_back(42);
        unit_test(!vec.empty(), "empty: vector should not be empty after push_back"); });

    REGISTER_TEST(vector_tests, []()
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
        unit_test(sum == 6, "iterator: sum of elements using iterator should be 6"); });

    REGISTER_TEST(vector_tests, []()
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
        unit_test(product == 6, "reverse_iterator: product of elements using reverse iterator should be 6"); });

    REGISTER_TEST(vector_tests, []()
                  {
        not_std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.clear();
        unit_test(vec.empty(), "clear: vector should be empty after clear");
        unit_test(vec.size() == 0, "clear: vector size should be 0 after clear"); });

    REGISTER_TEST(vector_tests, []()
                  {
        not_std::vector<int> vec;
        for (int i{0}; i < 1e6; i++)
        {
            vec.push_back(i);
        }
        unit_test(vec.size() == 1e6, "push_back_large_data: vector size should be 1e6 after adding 1e6 elements");
        unit_test(vec[999999] == 999999, "push_back_large_data: last element should be 999999"); });

    REGISTER_TEST(vector_tests, []()
                  {
        not_std::vector<int> vec;
        vec.reserve(2);
        auto initial_data_ptr = &vec[0];

        vec.push_back(1);
        vec.push_back(2);
        unit_test(&vec[0] == initial_data_ptr, "reallocation: data should not be reallocated after two push_backs");

        vec.push_back(3);
        unit_test(&vec[0] != initial_data_ptr, "reallocation: data should be reallocated after third push_back"); });

    // REGISTER_TEST(vector_tests, []()
    //               {
    //     not_std::vector<not_std::string> vec;
    //     vec.push_back("Hello");
    //     vec.push_back("World");
    //     unit_test(vec[0] == "Hello", "push_back_strings: first string should be 'Hello'");
    //     unit_test(vec[1] == "World", "push_back_strings: second string should be 'World'"); });

    REGISTER_TEST(vector_tests, []()
                  {
        not_std::vector<not_std::vector<int>> vec2d;
        not_std::vector<int> inner_vec;
        inner_vec.push_back(42);

        vec2d.push_back(inner_vec);
        unit_test(vec2d[0][0] == 42, "push_back_vector: inner vector's first element should be 42"); });
}