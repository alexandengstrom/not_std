#include <iostream>
#include <cassert>
#include "../include/data_structures/priority_queue.hpp"

void priority_queue_test_constructor()
{
    not_std::priority_queue<int> pq;
    assert(pq.empty());
    assert(pq.size() == 0);
}

void priority_queue_test_copy_constructor()
{
    not_std::priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);
    not_std::priority_queue<int> copied_pq = pq;

    assert(copied_pq.top() == 8);
    copied_pq.pop();
    assert(copied_pq.top() == 5);
    pq.pop();
    assert(pq.top() == 5);
}

void priority_queue_test_move_constructor()
{
    not_std::priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);

    not_std::priority_queue<int> moved_pq(std::move(pq));

    assert(moved_pq.top() == 8);
    moved_pq.pop();
    assert(moved_pq.top() == 5);
}

void priority_queue_test_copy_assignment()
{
    not_std::priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);
    not_std::priority_queue<int> another_pq;
    another_pq = pq;

    assert(another_pq.top() == 8);
    another_pq.pop();
    assert(another_pq.top() == 5);
    pq.pop();
    assert(pq.top() == 5);
}

void priority_queue_test_move_assignment()
{
    not_std::priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);
    not_std::priority_queue<int> another_pq;
    another_pq = std::move(pq);

    assert(another_pq.top() == 8);
    another_pq.pop();
    assert(another_pq.top() == 5);
}

void priority_queue_test_push_and_top()
{
    not_std::priority_queue<int> pq;
    pq.push(5);
    assert(pq.top() == 5);
    pq.push(3);
    assert(pq.top() == 5);
    pq.push(8);
    assert(pq.top() == 8);
    pq.push(1);
    assert(pq.top() == 8);
}

void priority_queue_test_pop()
{
    not_std::priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(1);
    pq.pop();
    assert(pq.top() == 5);
    pq.pop();
    assert(pq.top() == 3);
}

void priority_queue_test_clear()
{
    not_std::priority_queue<int> pq;
    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.clear();
    assert(pq.empty());
    assert(pq.size() == 0);
}

void test_priority_queue()
{
    std::cout << "Testing not_std::priority_queue: ";
    priority_queue_test_constructor();
    priority_queue_test_copy_constructor();
    priority_queue_test_move_constructor();
    priority_queue_test_copy_assignment();
    priority_queue_test_move_assignment();
    priority_queue_test_push_and_top();
    priority_queue_test_pop();
    priority_queue_test_clear();

    std::cout << "\033[32m\u2713\033[0m" << std::endl;
}