#ifndef NOT_STD_UNORDERED_MAP_HPP
#define NOT_STD_UNORDERED_MAP_HPP

#include "../common/common_defs.hpp"
#include "../algorithms/hash.hpp"
#include "../data_structures/pair.hpp"

namespace not_std
{
    template <typename K, typename V>
    class unordered_map
    {
    public:
        unordered_map();

        V &operator[](const K &key);
        const V &operator[](const K &key) const;

        bool empty() const noexcept;
        u_int size() const noexcept;
        void clear();
        void insert(const K &key, const V &value);

    private:
        enum class SlotState
        {
            EMPTY,
            OCCUPIED,
            TOMBSTONED
        };

        struct KeyValuePair
        {
            K key;
            V value;
            SlotState state{SlotState::EMPTY};
        };

        KeyValuePair *data;
        u_int current_size;
        u_int capacity;
        not_std::hash<K> hash_function;
        static constexpr float LOAD_FACTOR = 0.7f;
        static constexpr int GROWTH_FACTOR = 2;

        void rehash();

    public:
        class iterator
        {
        public:
            iterator(KeyValuePair *ptr = nullptr, u_int capacity = 0);

            iterator &operator++();
            not_std::pair<K, V> &operator*() const;
            bool operator!=(const iterator &other) const;

        private:
            KeyValuePair *ptr;
            u_int capacity;
        };

        iterator begin();
        iterator end();
    };

#include "impl/unordered_map_impl.hpp"

}

#endif