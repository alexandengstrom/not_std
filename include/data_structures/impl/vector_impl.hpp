#include "../../common/common_defs.hpp"

template <typename T>
not_std::vector<T>::vector() : data{nullptr}, current_size{0}, capacity{0} {}

template <typename T>
not_std::vector<T>::~vector()
{
    delete[] data;
}

template <typename T>
T &not_std::vector<T>::operator[](u_int index)
{
    return data[index];
}

template <typename T>
const T &not_std::vector<T>::operator[](u_int index) const
{
    return data[index];
}

template <typename T>
bool not_std::vector<T>::empty() const noexcept
{
    return current_size == 0;
}

template <typename T>
not_std::u_int not_std::vector<T>::size() const noexcept
{
    return current_size;
}

template <typename T>
void not_std::vector<T>::reserve(not_std::u_int new_capacity)
{
    if (new_capacity > capacity)
    {
        reallocate(new_capacity);
    }
}

template <typename T>
void not_std::vector<T>::shrink_to_fit()
{
    if (current_size == capacity)
    {
        return;
    }

    if (current_size == 0)
    {
        delete[] data;
        data = nullptr;
        capacity = 0;
        return;
    }

    T *new_data = new T[current_size];

    for (u_int i{0}; i < current_size; ++i)
    {
        new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
}

template <typename T>
void not_std::vector<T>::clear() noexcept
{
    delete[] data;
    data = nullptr;
    current_size = 0;
    capacity = 0;
}

template <typename T>
void not_std::vector<T>::push_back(const T &element)
{
    if (current_size == capacity)
    {
        u_int new_capacity = (capacity == 0) ? 1 : capacity * 2;
        reallocate(new_capacity);
    }

    data[current_size++] = element;
}

template <typename T>
void not_std::vector<T>::push_back(T &&element)
{
    if (current_size == capacity)
    {
        u_int new_capacity = (capacity == 0) ? 1 : capacity * 2;
        reallocate(new_capacity);
    }

    data[current_size++] = element;
}

template <typename T>
void not_std::vector<T>::reallocate(u_int new_capacity)
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

template <typename T>
typename not_std::vector<T>::iterator not_std::vector<T>::begin() noexcept
{
    return data;
}

template <typename T>
typename not_std::vector<T>::iterator not_std::vector<T>::end() noexcept
{
    return data + current_size;
}

template <typename T>
typename not_std::vector<T>::const_iterator not_std::vector<T>::begin() const noexcept
{
    return data;
}

template <typename T>
typename not_std::vector<T>::const_iterator not_std::vector<T>::end() const noexcept
{
    return data + current_size;
}

template <typename T>
typename not_std::vector<T>::const_iterator not_std::vector<T>::cbegin() const noexcept
{
    return data;
}

template <typename T>
typename not_std::vector<T>::const_iterator not_std::vector<T>::cend() const noexcept
{
    return data + current_size;
}

template <typename T>
typename not_std::vector<T>::reverse_iterator not_std::vector<T>::rbegin() noexcept
{
    return data + current_size - 1;
}

template <typename T>
typename not_std::vector<T>::reverse_iterator not_std::vector<T>::rend() noexcept
{
    return data - 1;
}

template <typename T>
typename not_std::vector<T>::const_reverse_iterator not_std::vector<T>::crbegin() const noexcept
{
    return data + current_size - 1;
}

template <typename T>
typename not_std::vector<T>::const_reverse_iterator not_std::vector<T>::crend() const noexcept
{
    return data - 1;
}
