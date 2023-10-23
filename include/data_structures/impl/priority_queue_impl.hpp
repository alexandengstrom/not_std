template <typename T>
not_std::priority_queue<T>::priority_queue() : data(nullptr), capacity(0), current_size(0) {}

template <typename T>
not_std::priority_queue<T>::priority_queue(const priority_queue<T> &other)
    : data(new T[other.capacity]), capacity(other.capacity), current_size(other.current_size)
{
    for (u_int i{0}; i < current_size; ++i)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
not_std::priority_queue<T>::priority_queue(priority_queue<T> &&other) noexcept
    : data(other.data), capacity(other.capacity), current_size(other.current_size)
{
    other.data = nullptr;
    other.capacity = 0;
    other.current_size = 0;
}

template <typename T>
not_std::priority_queue<T>::~priority_queue()
{
    delete[] data;
}

template <typename T>
not_std::priority_queue<T> &not_std::priority_queue<T>::operator=(const priority_queue<T> &other)
{
    if (this != &other)
    {
        delete[] data;

        capacity = other.capacity;
        current_size = other.current_size;
        data = new T[capacity];
        for (u_int i{0}; i < current_size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
not_std::priority_queue<T> &not_std::priority_queue<T>::operator=(priority_queue<T> &&other) noexcept
{
    if (this != &other)
    {
        delete[] data;

        data = other.data;
        capacity = other.capacity;
        current_size = other.current_size;

        other.data = nullptr;
        other.capacity = 0;
        other.current_size = 0;
    }
    return *this;
}

template <typename T>
void not_std::priority_queue<T>::push(const T &value)
{
    if (current_size == capacity)
    {
        resize(capacity == 0 ? 1 : capacity * 2);
    }

    data[current_size] = value;
    bubble_up(current_size);
    current_size++;
}

template <typename T>
void not_std::priority_queue<T>::pop()
{
    if (empty())
    {
        // TODO: Create exception
        throw;
    }

    data[0] = data[current_size - 1];
    current_size--;
    bubble_down(0);
}

template <typename T>
T not_std::priority_queue<T>::top() const
{
    return data[0];
}

template <typename T>
bool not_std::priority_queue<T>::empty() const
{
    return current_size == 0;
}

template <typename T>
u_int not_std::priority_queue<T>::size() const
{
    return current_size;
}

template <typename T>
void not_std::priority_queue<T>::clear()
{
    current_size = 0;
}

template <typename T>
void not_std::priority_queue<T>::resize(u_int new_capacity)
{
    T *new_data{new T[new_capacity]};
    for (size_t i{0}; i < current_size; ++i)
    {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

template <typename T>
void not_std::priority_queue<T>::bubble_up(u_int index)
{
    while (index && data[(index - 1) / 2] < data[index])
    {
        T temp = data[(index - 1) / 2];
        data[(index - 1) / 2] = data[index];
        data[index] = temp;
        index = (index - 1) / 2;
    }
}

template <typename T>
void not_std::priority_queue<T>::bubble_down(u_int index)
{
    u_int left{2 * index + 1};
    u_int right{2 * index + 2};
    u_int largest{index};

    if (left < current_size && data[largest] < data[left])
    {
        largest = left;
    }

    if (right < current_size && data[largest] < data[right])
    {
        largest = right;
    }

    if (largest != index)
    {
        T temp = data[index];
        data[index] = data[largest];
        data[largest] = temp;
        bubble_down(largest);
    }
}