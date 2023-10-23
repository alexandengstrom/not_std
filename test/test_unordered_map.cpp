#include "../include/data_structures/unordered_map.hpp"
#include "../include/data_structures/string.hpp"
#include <iostream>
#include <cassert>

void unordered_map_test_insert_and_retrieve()
{
    not_std::unordered_map<not_std::string, int> map;

    map.insert("one", 1);
    map.insert("two", 2);
    map.insert("three", 3);

    assert(map["one"] == 1);
    assert(map["two"] == 2);
    assert(map["three"] == 3);
}

void unordered_map_test_erase()
{
    not_std::unordered_map<not_std::string, int> map;
    map.insert("one", 1);
    map.insert("two", 2);
    map.erase("one");

    assert(map.size() == 1);
    assert(map["two"] == 2);
}

void unordered_map_test_rehash()
{
    not_std::unordered_map<int, int> map;

    for (int i{0}; i < 1000; i++)
    {
        map.insert(i, i * 2);
    }

    for (int i{0}; i < 1000; i++)
    {
        assert(map[i] == i * 2);
    }
}

void unordered_map_test_copy_and_move()
{
    not_std::unordered_map<int, int> map1;
    for (int i{0}; i < 100; i++)
    {
        map1.insert(i, i * 2);
    }

    not_std::unordered_map<int, int> map2 = map1;
    not_std::unordered_map<int, int> map3(std::move(map1));

    for (int i{0}; i < 100; i++)
    {
        assert(map2[i] == i * 2);
        assert(map3[i] == i * 2);
    }
}

void unordered_map_test_iteration()
{
    not_std::unordered_map<int, int> map;

    for (int i{0}; i < 10; i++)
    {
        map.insert(i, i * 2);
    }

    int count = 0;
    for (auto &pair : map)
    {
        assert(pair.second == pair.first * 2);
        count++;
    }

    assert(count == 10);
}

void test_unordered_map()
{
    std::cout << "Testing not_std::unordered_map: ";
    unordered_map_test_insert_and_retrieve();
    unordered_map_test_erase();
    unordered_map_test_rehash();
    unordered_map_test_copy_and_move();
    unordered_map_test_iteration();
    std::cout << "\033[32m\u2713\033[0m" << std::endl;
}
