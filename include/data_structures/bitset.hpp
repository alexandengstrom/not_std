#ifndef NOT_STD_BITSET_HPP
#define NOT_STD_BITSET_HPP

#include "../common/common_defs.hpp"

namespace not_std
{
    template <u_int N>
    class bitset
    {
    public:
        bitset();

        bool operator[](u_int pos) const;
        bitset<N> operator&(const bitset<N> &rhs) const;
        bitset<N> operator|(const bitset<N> &rhs) const;
        bitset<N> operator^(const bitset<N> &rhs) const;
        bitset<N> operator~() const;
        bitset<N> operator&=(const bitset<N> &rhs);
        bitset<N> operator|=(const bitset<N> &rhs);
        bitset<N> operator^=(const bitset<N> &rhs);

        bitset<N> &set();
        bitset<N> &set(u_int pos, bool value = true);
        bitset<N> &reset();
        bitset<N> &reset(u_int pos);
        bitset<N> &flip();
        bitset<N> &flip(u_int pos);
        u_int count();
        bool all() const;
        bool any() const;
        bool none() const;

    private:
        static constexpr lu_int num_blocks = (N + 63) / 64;
        unsigned long long data[num_blocks];
    };

#include "impl/bitset_impl.hpp"

}

#endif