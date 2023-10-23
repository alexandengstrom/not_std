#include "test_string.cpp"
#include "test_unordered_map.cpp"
#include "test_vector.cpp"
#include "test_pair.cpp"
#include "test_priority_queue.cpp"

#include <iostream>

int main()
{
    test_string();
    test_pair();
    test_unordered_map();
    test_vector();
    test_priority_queue();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}