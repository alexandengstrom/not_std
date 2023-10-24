#ifndef NOT_STD_LIST_HPP
#define NOT_STD_LIST_HPP

#include "../common/common_defs.hpp"

namespace not_std
{
    template <typename T>
    class list
    {
    public:
        list();
        ~list();

        T &front();
        T &back();
        bool empty() const noexcept;
        u_int size() const noexcept;
        void push_back(const T &value);
        void push_back(T &&value);
        void push_front(const T &value);
        void push_front(T &&value);
        void pop_back();
        void pop_front();

    private:
        class Node
        {
        public:
            Node();
            Node(T &value);
            Node(T &&value);
            ~Node();
            Node *next;
            Node *prev;
            T value;
        };

        Node *head;
        Node *tail;
        u_int current_size;
    };

#include "impl/list_impl.hpp"

}

#endif