#include "../../include/data_structures/deque.hpp"
#include "test_framework.hpp"

void register_deque_tests()
{

    REGISTER_TEST(deque_tests, []()
                  {
        std::cout << "Starting deque tests" << std::endl;
        not_std::deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);
        std::cout << "First test cleared" << std::endl;
        unit_test(deq.front() == 1, "push_back_and_access: front element should be 1");
        unit_test(deq.back() == 3, "push_back_and_access: back element should be 3"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        unit_test(deq.size() == 0, "size: deque size should be 0 initially");
        deq.push_back(42);
        std::cout << "1. DOES WE REACH THIS?" << std::endl;
        unit_test(deq.size() == 1, "size: deque size should be 1 after push_back"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        unit_test(deq.empty(), "empty: deque should be empty initially");
        deq.push_back(42);
                std::cout << "2. DOES WE REACH THIS?" << std::endl;
        unit_test(!deq.empty(), "empty: deque should not be empty after push_back"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        deq.push_back(1);
        deq.push_front(0);
        deq.push_back(3);
        deq.push_back(4);
                std::cout << "3. DOES WE REACH THIS?" << std::endl;
        unit_test(deq.front() == 0, "push_front_and_back: front element should be 0");
        unit_test(deq.back() == 4, "push_front_and_back: back element should be 4"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);
        deq.pop_front();
                std::cout << "4. DOES WE REACH THIS?" << std::endl;
        unit_test(deq.front() == 2, "pop_front: front element should be 2");
        unit_test(deq.size() == 2, "pop_front: size should be 2 after pop_front"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);
        deq.pop_back();
                std::cout << "5. DOES WE REACH THIS?" << std::endl;
        unit_test(deq.back() == 2, "pop_back: back element should be 2");
        unit_test(deq.size() == 2, "pop_back: size should be 2 after pop_back"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        for (int i{0}; i < 10000; i++)
        {
            deq.push_back(i);
        }

                std::cout << "6. DOES WE REACH THIS?" << std::endl;
        unit_test(deq.size() == 10000, "push_back_large_data: deque size should be 10000 after adding 1e5 elements");
        unit_test(deq.back() == 9999, "push_back_large_data: last element should be 9999"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        for (int i{0}; i < 10000; i++)
        {
            std::cout << i << std::endl;
            bool fail{false};
            deq.push_front(i);
            switch (deq.check_integrity()) {
                case 1: {
                    std::cout << "iteraton: " << i << std::endl;
                    fail = true;
                    std::cout << "Integrity check failed: block_count > max_blocks" << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "iteraton: " << i << std::endl;
                    fail = true;
                    std::cout << "Integrity check failed: data is nullptr but block_count or max_blocks is not in its initial state" << std::endl;
                    break;
                } case 3: {
                    std::cout << "iteraton: " << i << std::endl;
                    fail = true;
                    std::cout << "Integrity check failed: data beyond block_count is not nullptr" << std::endl;
                    break;
                } case 4: {
                    std::cout << "iteraton: " << i << std::endl;
                    fail = true;
                    std::cout << "Integrity check failed: current_size is 0 but front and back pointers/indices mismatch" << std::endl;
                    break;
                } default:
                {
                    break;
                }
            }

            if (fail) break;
        }

        std::cout << "7. DOES WE REACH THIS?" << std::endl;

        unit_test(deq.size() == 10000, "push_front_large_data: deque size should be 10000 after adding 1e5 elements");
        unit_test(deq.front() == 9999, "push_front_large_data: first element should be 9999"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        for (int i = 0; i < 10; ++i)
        {
            deq.push_back(i);
        }

        for (int i = 0; i < 5; ++i)
        {
            deq.pop_front();
        }

                std::cout << "8. DOES WE REACH THIS?" << std::endl;
        unit_test(deq.size() == 5, "pop_front_multiple: deque size should be 5 after popping front 5 times");
        unit_test(deq.front() == 5, "pop_front_multiple: front element should be 5 after popping front 5 times"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        for (int i = 0; i < 10; ++i)
        {
            deq.push_back(i);
        }

        for (int i = 0; i < 5; ++i)
        {
            deq.pop_back();
        }

                std::cout << "9. DOES WE REACH THIS?" << std::endl;
        unit_test(deq.size() == 5, "pop_back_multiple: deque size should be 5 after popping back 5 times");
        unit_test(deq.back() == 4, "pop_back_multiple: back element should be 4 after popping back 5 times"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        deq.push_back(1);
        deq.pop_front();
                std::cout << "10. DOES WE REACH THIS?" << std::endl;
        unit_test(deq.empty(), "pop_front_until_empty: deque should be empty after push_back followed by pop_front"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        deq.push_back(1);
        deq.pop_back();
                std::cout << "11. DOES WE REACH THIS?" << std::endl;
        unit_test(deq.empty(), "pop_back_until_empty: deque should be empty after push_back followed by pop_back"); });

    REGISTER_TEST(deque_tests, []()
                  {
        not_std::deque<int> deq;
        for (int i = 0; i < 100; ++i)
        {
            deq.push_back(i);
        }

        for (int i = 0; i < 50; ++i)
        {
            deq.pop_front();
        }

        for (int i = 0; i < 50; ++i)
        {
            deq.pop_back();
        }
                std::cout << "12. DOES WE REACH THIS?" << std::endl;
        unit_test(deq.empty(), "pop_front_and_back_until_empty: deque should be empty after popping all elements"); });

    // REGISTER_TEST(deque_tests, []()
    //               {
    //     const int NUM_ITEMS = 100;

    //     not_std::deque<int> deq;

    //     for (int i = 0; i < NUM_ITEMS; ++i)
    //     {
    //         deq.push_back(i);
    //     }
    //     unit_test(deq.size() == NUM_ITEMS, "large_data: deque size should be 1e6 after pushing 1e6 items using push_back");
    //     unit_test(deq.back() == NUM_ITEMS - 1, "large_data: last element should be 1e6-1 after push_back");

    //     for (int i = 1; i <= NUM_ITEMS; ++i)
    //     {
    //         deq.push_front(-i);
    //     }
    //     unit_test(deq.size() == 2 * NUM_ITEMS, "large_data: deque size should be 2e6 after pushing 1e6 items using push_front");
    //     unit_test(deq.front() == -NUM_ITEMS, "large_data: first element should be -1e6 after push_front");

    //     for (int i = 0; i < NUM_ITEMS / 2; ++i)
    //     {
    //         deq.pop_front();
    //     }
    //     unit_test(deq.size() == 1.5 * NUM_ITEMS, "large_data: deque size should be 1.5e6 after popping 0.5e6 items from the front");
    //     unit_test(deq.front() == -NUM_ITEMS / 2, "large_data: first element should be -0.5e6 after popping 0.5e6 items from the front");

    //     for (int i = 0; i < NUM_ITEMS / 2; ++i)
    //     {
    //         deq.pop_back();
    //     }
    //     unit_test(deq.size() == NUM_ITEMS, "large_data: deque size should be 1e6 after popping 0.5e6 items from the back");
    //     unit_test(deq.back() == NUM_ITEMS / 2 - 1, "large_data: last element should be 0.5e6-1 after popping 0.5e6 items from the back"); });

    std::cout << "finished tests" << std::endl;
}
