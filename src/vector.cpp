#include "../include/vector.hpp"

namespace not_std
{
    template <typename T>
    vector<T>::vector() : current_size(0), capacity(0), data(nullptr) {}

    template <typename T>
    void vector<T>::push_back(const T &element)
    {
        if (current_size == capacity)
        {
            u_int new_capacity = (capacity == 0) ? 1 : capacity * 2;
            reallocate(new_capacity);
        }

        data[current_size++] = element;
    }

    template <typename T>
    void vector<T>::reallocate(u_int new_capacity)
    {
        T *new_data{new T[new_capacity]};

        for (u_int i{0}; i < current_size; ++i)
        {
            new_data[i] = data[i];
        }

        delete[] data;

        data = new_data;
        capacity = new_capacity;
    }
}