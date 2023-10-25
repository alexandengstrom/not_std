template <u_int N>
not_std::bitset<N>::bitset()
{
    for (u_int i{0}; i < num_blocks; ++i)
    {
        data[i] = 0;
    }
}

template <u_int N>
bool not_std::bitset<N>::operator[](u_int pos) const
{
    return (data[pos / 64] & (1ULL << (pos % 64))) != 0;
}

template <u_int N>
bitset<N> not_std::bitset<N>::operator&(const bitset<N> &rhs) const
{
    bitset<N> result;
    for (u_int i{0}; i < num_blocks; ++i)
    {
        result.data[i] = data[i] & rhs.data[i];
    }
    return result;
}

template <u_int N>
bitset<N> not_std::bitset<N>::operator|(const bitset<N> &rhs) const
{
    bitset<N> result;
    for (u_int i{0}; i < num_blocks; ++i)
    {
        result.data[i] = data[i] | rhs.data[i];
    }
    return result;
}

template <u_int N>
bitset<N> not_std::bitset<N>::operator^(const bitset<N> &rhs) const
{
    bitset<N> result;
    for (u_int i{0}; i < num_blocks; ++i)
    {
        result.data[i] = data[i] ^ rhs.data[i];
    }
    return result;
}

template <u_int N>
bitset<N> not_std::bitset<N>::operator~() const
{
    bitset<N> result;
    for (u_int i{0}; i < num_blocks; ++i)
    {
        result.data[i] = ~data[i];
    }
    return result;
}

template <u_int N>
bitset<N> not_std::bitset<N>::operator&=(const bitset<N> &rhs)
{
    for (u_int i{0}; i < num_blocks; ++i)
    {
        data[i] &= rhs.data[i];
    }
    return *this;
}

template <u_int N>
bitset<N> not_std::bitset<N>::operator|=(const bitset<N> &rhs)
{
    for (u_int i{0}; i < num_blocks; ++i)
    {
        data[i] |= rhs.data[i];
    }
    return *this;
}

template <u_int N>
bitset<N> not_std::bitset<N>::operator^=(const bitset<N> &rhs)
{
    for (u_int i{0}; i < num_blocks; ++i)
    {
        data[i] ^= rhs.data[i];
    }
    return *this;
}

template <u_int N>
bitset<N> &not_std::bitset<N>::set()
{
    for (u_int i{0}; i < num_blocks; ++i)
    {
        data[i] = ~0ULL;
    }

    if (N % 64 != 0)
    {
        data[num_blocks - 1] &= (1ULL << (N % 64)) - 1;
    }

    return *this;
}

template <u_int N>
bitset<N> &not_std::bitset<N>::set(u_int pos, bool value)
{
    if (value)
    {
        data[pos / 64] |= (1ULL << (pos % 64));
    }
    else
    {
        data[pos / 64] &= ~(1ULL << (pos % 64));
    }

    return *this;
}

template <u_int N>
bitset<N> &not_std::bitset<N>::reset()
{
    for (u_int i{0}; i < num_blocks; ++i)
    {
        data[i] = 0;
    }
    return *this;
}

template <u_int N>
bitset<N> &not_std::bitset<N>::reset(u_int pos)
{
    data[pos / 64] &= ~(1ULL << (pos % 64));
    return *this;
}

template <u_int N>
bitset<N> &not_std::bitset<N>::flip()
{
    for (u_int i{0}; i < num_blocks; ++i)
    {
        data[i] = ~data[i];
    }
    return *this;
}

template <u_int N>
bitset<N> &not_std::bitset<N>::flip(u_int pos)
{
    data[pos / 64] ^= (1ULL << (pos % 64));
    return *this;
}

template <u_int N>
u_int not_std::bitset<N>::count()
{
    u_int true_bits{0};
    for (u_int i{0}; i < num_blocks; ++i)
    {
        // This is specific for GCC, wont work with other compilers.
        true_bits += __builtin_popcountll(data[i]);

        // If using another compiler use this code instead:

        // unsigned long long n{i};
        // int count = 0;
        // while (n)
        // {
        //     n &= (n - 1);
        //     count++;
        // }
        // true_bits += count;
    }
    return true_bits;
}

template <u_int N>
bool not_std::bitset<N>::all() const
{
    for (u_int i{0}; i < num_blocks - 1; ++i)
    {
        if (data[i] != ~0ULL)
            return false;
    }

    if (N % 64 != 0)
    {
        return data[num_blocks - 1] == ((1ULL << (N % 64)) - 1);
    }
    return data[num_blocks - 1] == ~0ULL;
}

template <u_int N>
bool not_std::bitset<N>::any() const
{
    for (u_int i{0}; i < num_blocks; ++i)
    {
        if (data[i])
            return true;
    }
    return false;
}

template <u_int N>
bool not_std::bitset<N>::none() const
{
    return !any();
}
