#include "../../include/data_structures/priority_queue.hpp"
#include "test_framework.hpp"

void register_priority_queue_tests()
{
    REGISTER_TEST(priority_queue_tests, []()
                  {
        not_std::priority_queue<int> pq;
        unit_test(pq.empty(), "Constructor: queue should be empty");
        unit_test(pq.size() == 0, "Constructor: queue size should be 0"); });

    REGISTER_TEST(priority_queue_tests, []()
                  {
        not_std::priority_queue<int> pq;
        pq.push(5);
        pq.push(3);
        pq.push(8);
        not_std::priority_queue<int> copied_pq = pq;
        unit_test(copied_pq.top() == 8, "Copy Constructor: copied queue's top should be 8");
        copied_pq.pop();
        unit_test(copied_pq.top() == 5, "Copy Constructor: after pop, copied queue's top should be 5");
        pq.pop();
        unit_test(pq.top() == 5, "Copy Constructor: original queue's top after pop should be 5"); });

    REGISTER_TEST(priority_queue_tests, []()
                  {
        not_std::priority_queue<int> pq;
        pq.push(5);
        pq.push(3);
        pq.push(8);
        not_std::priority_queue<int> moved_pq(std::move(pq));
        unit_test(moved_pq.top() == 8, "Move Constructor: moved queue's top should be 8");
        moved_pq.pop();
        unit_test(moved_pq.top() == 5, "Move Constructor: after pop, moved queue's top should be 5"); });

    REGISTER_TEST(priority_queue_tests, []()
                  {
        not_std::priority_queue<int> pq;
        pq.push(5);
        pq.push(3);
        pq.push(8);
        not_std::priority_queue<int> another_pq;
        another_pq = pq;
        unit_test(another_pq.top() == 8, "Copy Assignment: another queue's top should be 8");
        another_pq.pop();
        unit_test(another_pq.top() == 5, "Copy Assignment: after pop, another queue's top should be 5");
        pq.pop();
        unit_test(pq.top() == 5, "Copy Assignment: original queue's top after pop should be 5"); });

    REGISTER_TEST(priority_queue_tests, []()
                  {
        not_std::priority_queue<int> pq;
        pq.push(5);
        pq.push(3);
        pq.push(8);
        not_std::priority_queue<int> another_pq;
        another_pq = std::move(pq);
        unit_test(another_pq.top() == 8, "Move Assignment: another queue's top should be 8");
        another_pq.pop();
        unit_test(another_pq.top() == 5, "Move Assignment: after pop, another queue's top should be 5"); });

    REGISTER_TEST(priority_queue_tests, []()
                  {
        not_std::priority_queue<int> pq;
        pq.push(5);
        unit_test(pq.top() == 5, "Push and Top: after first push, top should be 5");
        pq.push(3);
        unit_test(pq.top() == 5, "Push and Top: after second push, top should be 5");
        pq.push(8);
        unit_test(pq.top() == 8, "Push and Top: after third push, top should be 8");
        pq.push(1);
        unit_test(pq.top() == 8, "Push and Top: after fourth push, top should be 8"); });

    REGISTER_TEST(priority_queue_tests, []()
                  {
        not_std::priority_queue<int> pq;
        pq.push(5);
        pq.push(3);
        pq.push(8);
        pq.push(1);
        pq.pop();
        unit_test(pq.top() == 5, "Pop: after first pop, top should be 5");
        pq.pop();
        unit_test(pq.top() == 3, "Pop: after second pop, top should be 3"); });

    REGISTER_TEST(priority_queue_tests, []()
                  {
        not_std::priority_queue<int> pq;
        pq.push(5);
        pq.push(3);
        pq.push(8);
        pq.clear();
        unit_test(pq.empty(), "Clear: queue should be empty after clear");
        unit_test(pq.size() == 0, "Clear: queue size should be 0 after clear"); });

    REGISTER_TEST(priority_queue_tests, []()
                  {
        not_std::priority_queue<int> pq;
        const int NUM_VALUES = 100000;
        for (int i = 0; i < NUM_VALUES; ++i)
        {
            pq.push(i);
        }

        pq.push(NUM_VALUES * 10);
        unit_test(pq.top() == NUM_VALUES * 10, "Stress Test: top value should be 1 million after insertions");
        pq.pop();

        int expected_value = NUM_VALUES - 1;
        while (!pq.empty())
        {
            unit_test(pq.top() == expected_value, "Stress Test: incorrect value during sequential pop");
            if (pq.top() != expected_value) {
                break;
            }
            pq.pop();
            --expected_value;
        } });
}