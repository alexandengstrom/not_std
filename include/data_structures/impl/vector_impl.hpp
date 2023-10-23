#include "../../common/common_defs.hpp"

template <typename T>
not_std::vector<T>::vector() : data{nullptr}, current_size{0}, capacity{0} {}

template <typename T>
not_std::vector<T>::vector(const not_std::vector<T> &other)
    : data(nullptr), current_size(other.current_size), capacity(other.capacity)
{
    if (other.data)
    {
        data = new T[capacity];
        for (u_int i{0}; i < current_size; ++i)
        {
            data[i] = other.data[i];
        }
    }
}

template <typename T>
not_std::vector<T>::vector(not_std::vector<T> &&other) noexcept
    : data(other.data), current_size(other.current_size), capacity(other.capacity)
{
    other.data = nullptr;
    other.current_size = 0;
    other.capacity = 0;
}

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
not_std::vector<T> &not_std::vector<T>::operator=(const vector<T> &other)
{
    if (this != &other)
    {
        if (data)
        {
            delete[] data;
        }

        current_size = other.current_size;
        capacity = other.capacity;
        data = new T[capacity];

        for (u_int i = 0; i < current_size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    return *this;
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
not_std::vector<T>::iterator::iterator(T *p) : ptr(p) {}

template <typename T>
typename not_std::vector<T>::iterator &not_std::vector<T>::iterator::operator++()
{
    ++ptr;
    return *this;
}

template <typename T>
T &not_std::vector<T>::iterator::operator*() const
{
    return *ptr;
}

template <typename T>
bool not_std::vector<T>::iterator::operator!=(const not_std::vector<T>::iterator &other) const
{
    return ptr != other.ptr;
}

template <typename T>
typename not_std::vector<T>::iterator not_std::vector<T>::begin()
{
    return iterator(data);
}

template <typename T>
typename not_std::vector<T>::iterator not_std::vector<T>::end()
{
    return iterator(data + current_size);
}

template <typename T>
not_std::vector<T>::reverse_iterator::reverse_iterator(T *ptr) : ptr(ptr) {}

template <typename T>
typename not_std::vector<T>::reverse_iterator &not_std::vector<T>::reverse_iterator::operator++()
{
    --ptr;
    return *this;
}

template <typename T>
T &not_std::vector<T>::reverse_iterator::operator*() const
{
    return *ptr;
}

template <typename T>
bool not_std::vector<T>::reverse_iterator::operator!=(const not_std::vector<T>::reverse_iterator &other) const
{
    return ptr != other.ptr;
}

template <typename T>
typename not_std::vector<T>::reverse_iterator not_std::vector<T>::rbegin()
{
    return reverse_iterator(data + current_size - 1);
}

template <typename T>
typename not_std::vector<T>::reverse_iterator not_std::vector<T>::rend()
{
    return reverse_iterator(data - 1);
}
