#include "../../include/data_structures/deque.hpp"
#include "test_framework.hpp"

void register_deque_tests()
{
    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);
        unit_test(deq.front() == 1, "push_back_and_access: front element should be 1");
        unit_test(deq.back() == 3, "push_back_and_access: back element should be 3"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        unit_test(deq.size() == 0, "size: deque size should be 0 initially");
        deq.push_back(42);
        unit_test(deq.size() == 1, "size: deque size should be 1 after push_back"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        unit_test(deq.empty(), "empty: deque should be empty initially");
        deq.push_back(42);
        unit_test(!deq.empty(), "empty: deque should not be empty after push_back"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        deq.push_back(1);
        deq.push_front(0);
        deq.push_back(3);
        deq.push_back(4);
        unit_test(deq.front() == 0, "push_front_and_back: front element should be 0");
        unit_test(deq.back() == 4, "push_front_and_back: back element should be 4"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);
        deq.pop_front();
        unit_test(deq.front() == 2, "pop_front: front element should be 2");
        unit_test(deq.size() == 2, "pop_front: size should be 2 after pop_front"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);
        deq.pop_back();
        unit_test(deq.back() == 2, "pop_back: back element should be 2");
        unit_test(deq.size() == 2, "pop_back: size should be 2 after pop_back"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        for (int i{0}; i < 10000; i++)
        {
            bool fail{false};
            deq.push_back(i);
            switch (deq.check_integrity()) {
                case 1: {
                    std::cout << "iteraton: " << i << std::endl;
                    fail = true;
                    std::cout << "Integrity check failed: block_count > max_blocks" << std::endl;
                }
                case 2: {
                    std::cout << "iteraton: " << i << std::endl;
                    fail = true;
                    std::cout << "Integrity check failed: data is nullptr but block_count or max_blocks is not in its initial state" << std::endl;
                } case 3: {
                    std::cout << "iteraton: " << i << std::endl;
                    fail = true;
                    std::cout << "Integrity check failed: data beyond block_count is not nullptr" << std::endl;
                } case 4: {
                    std::cout << "iteraton: " << i << std::endl;
                    fail = true;
                    std::cout << "Integrity check failed: current_size is 0 but front and back pointers/indices mismatch" << std::endl;
                } default:
                {
                    break;
                }
            }

            if (fail) break;
        }

        std::cout << deq.back() << std::endl;
        unit_test(deq.size() == 10000, "push_back_large_data: deque size should be 10000 after adding 1e5 elements");
        unit_test(deq.back() == 9999, "push_back_large_data: last element should be 9999"); });
}
