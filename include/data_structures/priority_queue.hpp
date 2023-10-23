#ifndef NOT_STD_PRIORITY_QUEUE_HPP
#define NOT_STD_PRIORITY_QUEUE_HPP

#include "../common/common_defs.hpp"

namespace not_std
{
    template <typename T>
    class priority_queue
    {
    public:
        priority_queue();
        ~priority_queue();
        priority_queue(const priority_queue<T> &other);
        priority_queue(priority_queue<T> &&other) noexcept;

        priority_queue<T> &operator=(const priority_queue<T> &other);
        priority_queue<T> &operator=(priority_queue<T> &&other) noexcept;

        void push(const T &value);
        void pop();
        T top() const;
        bool empty() const;
        u_int size() const;
        void clear();

    private:
        T *data;
        u_int capacity;
        u_int current_size;

        void resize(u_int new_capacity);
        void bubble_up(u_int index);
        void bubble_down(u_int index);
    };

#include "impl/priority_queue_impl.hpp"

}

#endif