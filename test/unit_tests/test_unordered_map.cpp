#include "../../include/data_structures/unordered_map.hpp"
#include "test_framework.hpp"

void register_unordered_map_tests()
{
    REGISTER_TEST(unordered_map_tests, ([&]()
                                        {
        not_std::unordered_map<not_std::string, int> map;

        map.insert("one", 1);
        map.insert("two", 2);
        map.insert("three", 3);

        unit_test(map["one"] == 1, "insert_and_retrieve: Value for key 'one' should be 1");
        unit_test(map["two"] == 2, "insert_and_retrieve: Value for key 'two' should be 2");
        unit_test(map["three"] == 3, "insert_and_retrieve: Value for key 'three' should be 3"); }));

    REGISTER_TEST(unordered_map_tests, ([&]()
                                        {
        not_std::unordered_map<not_std::string, int> map;
        map.insert("one", 1);
        map.insert("two", 2);
        map.erase("one");

        unit_test(map.size() == 1, "erase: Map size should be 1 after erasing one element");
        unit_test(map["two"] == 2, "erase: Value for key 'two' should be 2"); }));

    REGISTER_TEST(unordered_map_tests, ([&]()
                                        {
        not_std::unordered_map<int, int> map;

        for (int i{0}; i < 40; i++)
        {
            map.insert(i, i * 2);
        }

        for (int i{0}; i < 40; i++)
        {
            unit_test(map[i] == i * 2, "rehash: Value for key after rehash should match");
        } }));

    REGISTER_TEST(unordered_map_tests, ([&]()
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
            unit_test(map2[i] == i * 2, "copy_and_move: Value for key in copied map should match");
            unit_test(map3[i] == i * 2, "copy_and_move: Value for key in moved map should match");
        } }));

    REGISTER_TEST(unordered_map_tests, ([&]()
                                        {
        not_std::unordered_map<int, int> map;

        for (int i{0}; i < 10; i++)
        {
            map.insert(i, i * 2);
        }

        int count = 0;
        for (auto &pair : map)
        {
            unit_test(pair.second == pair.first * 2, "iteration: Value should be twice the key");
            count++;
        }

        unit_test(count == 10, "iteration: Iteration count should be 10"); }));

    REGISTER_TEST(unordered_map_tests, ([&]()
                                        {
        not_std::unordered_map<not_std::string, int> umap;
        for (int i = 0; i < 100; ++i)
        {
            umap.insert(not_std::string("key") + std::to_string(i), i);
        }

        for (int i = 0; i < 100 / 2; ++i)
        {
            int v = umap[not_std::string("key") + std::to_string(i)];
            unit_test(v == i, "access data: Value should be correct");
        }

        for (auto it{umap.begin()}; it != umap.end(); ++it)
        {
            auto [k, v] = *it;
        } }));
}
