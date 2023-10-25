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
        // Constructors and destructors
        unordered_map();
        unordered_map(const unordered_map &other);
        unordered_map(unordered_map &&other);
        ~unordered_map();

        // Operators
        V &operator[](const K &key);
        const V &operator[](const K &key) const;
        unordered_map<K, V> &operator=(const unordered_map<K, V> &other);
        unordered_map<K, V> &operator=(unordered_map<K, V> &&other);

        bool empty() const noexcept;
        u_int size() const noexcept;
        void clear();
        void insert(const K &key, const V &value);
        lu_int erase(const K &key);

    private:
        enum class SlotState
        {
            EMPTY,
            OCCUPIED,
            TOMBSTONED
        };

        struct KeyValuePair
        {
            not_std::pair<K, V> pair;
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
            iterator(KeyValuePair *ptr, KeyValuePair *map_end);

            iterator &operator++();
            not_std::pair<K, V> &operator*() const;
            bool operator!=(const iterator &other) const;

        private:
            KeyValuePair *ptr;
            KeyValuePair *map_end;
        };

        iterator begin();
        iterator end();
    };

#include "impl/unordered_map_impl.hpp"

}

#endif