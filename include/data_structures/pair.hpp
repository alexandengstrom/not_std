#ifndef NOT_STD_PAIR_HPP
#define NOT_STD_PAIR_HPP

namespace not_std
{

    template <typename T1, typename T2>
    class pair
    {
    public:
        T1 first;
        T2 second;

        pair();
        pair(const T1 &a, const T2 &b);
        pair(const not_std::pair<T1, T2> &other);
        pair &operator=(const pair &p);
        bool operator==(const pair &p) const;
        bool operator!=(const pair &other) const;
        bool operator<(const pair &other) const;
    };

#include "impl/pair_impl.hpp"

}

#endif
