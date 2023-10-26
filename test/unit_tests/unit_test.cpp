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

    register_list_tests();
    run_tests(list_tests, "not_std::list");

    register_set_tests();
    run_tests(set_tests, "not_std::set");

    register_bitset_tests();
    run_tests(bitset_tests, "not_std::bitset");

    register_deque_tests();
    run_tests(deque_tests, "not_std::deque");

    return 0;
}
