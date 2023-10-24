#include "test_framework.hpp"

int main()
{
    register_string_tests();
    run_tests(string_tests, "not_std::string");

    register_pair_tests();
    run_tests(pair_tests, "not_std::pair");

    register_priority_queue_tests();
    run_tests(priority_queue_tests, "not_std::priority_queue");

    register_vector_tests();
    run_tests(vector_tests, "not_std::vector");

    register_unordered_map_tests();
    run_tests(unordered_map_tests, "not_std::unordered_map");

    return 0;
}
