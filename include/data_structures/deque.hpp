#ifndef NOT_STD_DEQUE_HPP
#define NOT_STD_DEQUE_HPP

#include "../common/common_defs.hpp"

namespace not_std
{

    template <typename T>
    class deque
    {
    public:
        deque();
        ~deque();

        int check_integrity() const;

        T &front() const;
        T &back() const;

        void push_front(const T &value);
        void push_back(const T &value);

        void pop_front();
        void pop_back();

        u_int size() const;
        bool empty() const;

    private:
        static const u_int BLOCK_SIZE = 16;

        T **data;
        u_int block_count;
        u_int max_blocks;

        T *front_block;
        T *back_block;

        u_int front_index;
        u_int back_index;

        u_int current_size;

        void allocate_front();
        void allocate_back();
        void deallocate_front();
        void deallocate_back();
    };

#include "impl/deque_impl.hpp"

}

#endif