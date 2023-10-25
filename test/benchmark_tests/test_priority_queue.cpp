#include "test_framework.hpp"
#include <queue>
#include "../../include/data_structures/priority_queue.hpp"

void benchmark_not_std_priority_queue(int NUM_ELEMENTS)
{
    not_std::priority_queue<int> pq;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        pq.push(i);

        if (i % 2 == 0 && !pq.empty())
        {
            int top_val = pq.top();
        }

        if (i % 3 == 0 && !pq.empty())
        {
            pq.pop();
        }

        pq.size();
    }

    while (!pq.empty())
    {
        pq.pop();
    }
}

void benchmark_std_priority_queue(int NUM_ELEMENTS)
{
    std::priority_queue<int> pq;
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        pq.push(i);

        if (i % 2 == 0 && !pq.empty())
        {
            int top_val = pq.top();
        }

        if (i % 3 == 0 && !pq.empty())
        {
            pq.pop();
        }

        pq.size();
    }

    while (!pq.empty())
    {
        pq.pop();
    }
}

void priority_queue_small_test()
{
    compare_benchmarks(
        "priority_queue",
        [&]()
        { benchmark_not_std_priority_queue(100000); },
        [&]()
        { benchmark_std_priority_queue(100000); },
        100000);
}

void priority_queue_big_test()
{
    compare_benchmarks(
        "priority_queue",
        [&]()
        { benchmark_not_std_priority_queue(10000000); },
        [&]()
        { benchmark_std_priority_queue(10000000); },
        10000000);
}

void register_priority_queue_test()
{
    priority_queue_small_test();
    priority_queue_big_test();
}
