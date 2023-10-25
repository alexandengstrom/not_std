#ifndef NOT_STD_SET_HPP
#define NOT_STD_SET_HPP

#include <string>
#include "../common/common_defs.hpp"

namespace not_std
{
    template <typename T>
    class set
    {
    public:
        set();
        ~set();

        void insert(const T &value);
        void erase(const T &value);
        bool contains(const T &value);
        bool empty() const;
        u_int size() const;

    private:
        enum Color
        {
            RED,
            BLACK
        };

        class Node
        {
        public:
            T value;
            Node *parent;
            Node *left;
            Node *right;
            Color color;

            bool is_on_left();
            bool has_red_child();

        private:
        };

        Node *root;
        u_int current_size;

        Node *search(const T &value);
        void fix_violations(Node *inserted);
        void fix_double_black(Node *x);
        void rotate_left(Node *x);
        void rotate_right(Node *y);
        Node *search(const T &value) const;
        Node *create_node(const T &value, Color color, Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr);
        Node *remove_node(const T &value);

    public:
        class iterator
        {
        public:
            iterator(Node *start);
            iterator();
            T &operator*();
            iterator &operator++();
            bool operator!=(const iterator &other);

        private:
            Node *ptr;
        };

        iterator begin();
        iterator end();

        class reverse_iterator
        {
        public:
            reverse_iterator(Node *start);
            reverse_iterator();
            T &operator*();
            reverse_iterator &operator++();
            bool operator!=(const reverse_iterator &other);

        private:
            Node *ptr;
        };

        reverse_iterator rbegin();
        reverse_iterator rend();

        // ONLY WHILE BUILDING THE CLASS TO SEE THAT IT WORKS:
        std::string print_tree() const;
        std::string print_tree(Node *node, int depth) const;
        std::string indent(int depth) const;
    };

#include "impl/set_impl.hpp"

}

#endif
