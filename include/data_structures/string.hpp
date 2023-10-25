#ifndef NOT_STD_STRING_HPP
#define NOT_STD_STRING_HPP

#include "../common/common_defs.hpp"
#include <iostream>
#include <string>

namespace not_std
{

    class string
    {
    public:
        // Constructors and destructors
        inline string();
        inline string(const char *cstr);
        inline string(const string &other);
        inline string(string &&other) noexcept;
        inline ~string();

        // Operators
        inline string &operator=(const string &other);
        inline string &operator=(string &&other) noexcept;
        inline char &operator[](lu_int pos);
        inline const char &operator[](lu_int pos) const;
        inline bool operator==(const string &other) const;
        inline bool operator==(const char *cstr) const;
        inline bool operator!=(const string &other) const;
        inline bool operator!=(const char *cstr) const;
        inline string &operator+=(const string &other);
        inline string &operator+=(const char *other);
        inline string operator+(const not_std::string &rhs);
        inline string operator+(const char *rhs);
        inline string operator+(const std::string &rhs);

        inline lu_int length() const noexcept;
        inline bool empty() const noexcept;
        inline char at(u_int pos) const;
        inline void clear();
        inline void push_back(char c);

    private:
        char *data;
        lu_int current_size;
        lu_int capacity;

        inline void reallocate(u_int new_size);
    };

#include "impl/string_impl.hpp"

}

#endif
