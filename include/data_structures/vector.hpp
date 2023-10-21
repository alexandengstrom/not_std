#ifndef NOT_STD_VECTOR_HPP
#define NOT_STD_VECTOR_HPP

#include "../common/common_defs.hpp"

namespace not_std
{
    template <typename T>
    class vector
    {
    public:
        using iterator = T *;
        using const_iterator = const T *;
        using reverse_iterator = T *;
        using const_reverse_iterator = T *;

        // Constructors
        vector();

        // Operators
        T &operator[](u_int index);
        const T &operator[](u_int index) const;

        // Public Member Functions
        bool empty() const noexcept;
        u_int size() const noexcept;
        void reserve(u_int new_capacity);
        void shrink_to_fit();
        void clear() noexcept;
        void push_back(const T &element);
        void push_back(T &&value);

        // Iterators
        iterator begin() noexcept;
        iterator end() noexcept;
        const_iterator begin() const noexcept;
        const_iterator end() const noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;
        reverse_iterator rbegin() noexcept;
        reverse_iterator rend() noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend() const noexcept;

    private:
        T *data;
        u_int current_size;
        u_int capacity;

        void reallocate(u_int new_capacity);
    };

#include "../not_std_detail/vector_impl.hpp"

}

#endif