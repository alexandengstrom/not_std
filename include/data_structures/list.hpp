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
        list(const list<T> &other);
        list(list<T> &&other) noexcept;
        ~list();

        list<T> &operator=(const not_std::list<T> &other);
        list<T> &operator=(not_std::list<T> &&other) noexcept;

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
            Node(const T &value);
            Node(T &&value);
            ~Node();
            Node *next;
            Node *prev;
            T value;
        };

        Node *head;
        Node *tail;
        u_int current_size;

    public:
        class iterator
        {
        public:
            iterator(Node *node);

            T &operator*();
            iterator &operator++();

            bool operator!=(const iterator &other) const;

        private:
            Node *current_node;
        };

        iterator begin();
        iterator end();

        class reverse_iterator
        {
        public:
            reverse_iterator(Node *node);

            T &operator*();
            reverse_iterator &operator++();

            bool operator!=(const reverse_iterator &other) const;

        private:
            Node *current_node;
        };

        reverse_iterator rbegin();
        reverse_iterator rend();
    };

#include "impl/list_impl.hpp"

}

#endif