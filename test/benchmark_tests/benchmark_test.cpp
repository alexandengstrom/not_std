#include "test_framework.hpp"

int main()
{
    register_vector_test();
    register_unordered_map_test();
    register_list_test();
    register_priority_queue_test();
    register_string_test();
    return 0;
}