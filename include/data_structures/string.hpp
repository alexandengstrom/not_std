#ifndef NOT_STD_STRING_HPP
#define NOT_STD_STRING_HPP

#include "../common/common_defs.hpp"
#include <iostream>

namespace not_std
{

    class string
    {
    public:
        // Constructors and destructors
        string();
        string(const char *cstr);
        string(const string &other);
        string(string &&other) noexcept;
        ~string();

        // Operators
        string &operator=(const string &other);
        string &operator=(string &&other) noexcept;
        char &operator[](lu_int pos);
        const char &operator[](lu_int pos) const;
        bool operator==(const string &other) const;
        bool operator==(const char *cstr) const;
        bool operator!=(const string &other) const;
        bool operator!=(const char *cstr) const;

        // Capacity
        lu_int length() const noexcept;
        bool empty() const noexcept;
        char at(u_int pos) const;

        // Modifiers
        void clear();
        void push_back(char c);

    private:
        char *data;
        lu_int current_size;
        lu_int capacity;

        void reallocate(u_int new_size);
    };

#include "impl/string_impl.hpp"

}

#endif
