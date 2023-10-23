#ifndef NOT_STD_VECTOR_HPP
#define NOT_STD_VECTOR_HPP

#include "../common/common_defs.hpp"

namespace not_std
{
    template <typename T>
    class vector
    {
    public:
        // Constructors
        vector();
        vector(const vector<T> &other);
        vector(not_std::vector<T> &&other) noexcept;
        ~vector();

        // Operators
        T &operator[](u_int index);
        const T &operator[](u_int index) const;
        vector<T> &operator=(const not_std::vector<T> &other);

        // Public Member Functions
        bool empty() const noexcept;
        u_int size() const noexcept;
        void reserve(u_int new_capacity);
        void shrink_to_fit();
        void clear() noexcept;
        void push_back(const T &element);
        void push_back(T &&value);

        // Iterators
        class iterator
        {
        public:
            iterator(T *p = nullptr);
            iterator &operator++();
            T &operator*() const;
            bool operator!=(const iterator &other) const;

        private:
            T *ptr;
        };

        iterator begin();
        iterator end();

        class reverse_iterator
        {
        public:
            reverse_iterator(T *p = nullptr);
            reverse_iterator &operator++();
            T &operator*() const;
            bool operator!=(const reverse_iterator &other) const;

        private:
            T *ptr;
        };

        reverse_iterator rbegin();
        reverse_iterator rend();

    private:
        T *data;
        u_int current_size;
        u_int capacity;

        void reallocate(u_int new_capacity);
    };

#include "impl/vector_impl.hpp"

}

#endif