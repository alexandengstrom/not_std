template <typename T>
not_std::deque<T>::deque() : data{nullptr},
                             block_count{0},
                             max_blocks{BLOCK_SIZE},
                             front_block{nullptr},
                             back_block{nullptr},
                             front_index{0},
                             back_index{0},
                             current_size{0}

{
    data = new T *[BLOCK_SIZE];
    for (u_int i{0}; i < BLOCK_SIZE; ++i)
    {
        data[i] = nullptr;
    }

    allocate_back();
    front_block = back_block;
}

template <typename T>
not_std::deque<T>::~deque()
{
    for (u_int i{0}; i < block_count; ++i)
    {
        delete[] data[i];
        data[i] = nullptr;
    }
    delete[] data;
}

template <typename T>
T &not_std::deque<T>::front() const
{
    return front_block[front_index];
}

template <typename T>
T &not_std::deque<T>::back() const
{
    if (back_index == 0)
    {
        return back_block[BLOCK_SIZE - 1];
    }
    else
    {
        return back_block[back_index - 1];
    }
}

template <typename T>
void not_std::deque<T>::push_front(const T &value)
{
    if (front_index == 0)
    {
        allocate_front();
        front_index = BLOCK_SIZE - 1;
    }
    else
    {
        --front_index;
    }
    front_block[front_index] = value;
    ++current_size;
}

template <typename T>
void not_std::deque<T>::push_back(const T &value)
{
    if (back_index == BLOCK_SIZE - 1)
    {
        allocate_back();
        back_block[back_index] = value;
        back_index = 0;
    }
    else
    {
        back_block[back_index] = value;
        ++back_index;
    }
    ++current_size;
}

template <typename T>
void not_std::deque<T>::pop_front()
{
    ++front_index;
    if (front_index == BLOCK_SIZE)
    {
        deallocate_front();
        front_index = 0;
    }
    --current_size;
}

template <typename T>
void not_std::deque<T>::pop_back()
{
    if (back_index == 0)
    {
        deallocate_back();
        back_index = BLOCK_SIZE - 1;
    }
    else
    {
        --back_index;
    }
    --current_size;
}

template <typename T>
u_int not_std::deque<T>::size() const
{
    return current_size;
}

template <typename T>
bool not_std::deque<T>::empty() const
{
    return current_size == 0;
}

template <typename T>
void not_std::deque<T>::allocate_front()
{
    if (block_count == max_blocks)
    {
        T **new_data = new T *[max_blocks + BLOCK_SIZE];
        for (u_int i = 0; i < block_count; ++i)
        {
            new_data[i + 1] = data[i];
        }

        new_data[0] = nullptr;

        for (u_int i = block_count + 1; i < max_blocks + BLOCK_SIZE; ++i)
        {
            new_data[i] = nullptr;
        }

        delete[] data;
        data = new_data;
        max_blocks += BLOCK_SIZE;
    }

    data[0] = new T[BLOCK_SIZE];
    ++block_count;
    front_block = data[0];
}

template <typename T>
void not_std::deque<T>::allocate_back()
{
    if (block_count == max_blocks)
    {
        T **new_data = new T *[max_blocks + BLOCK_SIZE];
        for (u_int i{0}; i < block_count; ++i)
        {
            new_data[i] = data[i];
        }
        for (u_int i{block_count}; i < max_blocks + BLOCK_SIZE; ++i)
        {
            new_data[i] = nullptr;
        }

        delete[] data;
        data = new_data;
        max_blocks += BLOCK_SIZE;
    }

    data[block_count] = new T[BLOCK_SIZE];
    ++block_count;
    back_block = data[block_count - 1];
}

template <typename T>
void not_std::deque<T>::deallocate_front()
{
    delete[] data[0];

    for (u_int i{0}; i < block_count - 1; ++i)
    {
        data[i] = data[i + 1];
    }

    data[block_count - 1] = nullptr;
    --block_count;
    front_block = (block_count == 0) ? nullptr : data[0];
    back_block = data[block_count - 1];
}

template <typename T>
void not_std::deque<T>::deallocate_back()
{
    delete[] data[block_count - 1];
    data[block_count - 1] = nullptr;
    --block_count;

    if (block_count == 0)
    {
        front_block = nullptr;
        back_block = nullptr;
    }
    else
    {
        back_block = data[block_count - 1];
    }
}

template <typename T>
int not_std::deque<T>::check_integrity() const
{
    if (block_count > max_blocks)
    {
        return 1;
    }

    if (data == nullptr && (block_count != 0 || max_blocks != BLOCK_SIZE))
    {
        return 2;
    }

    for (u_int i = block_count; i < max_blocks; ++i)
    {
        if (data[i] != nullptr)
        {
            return 3;
        }
    }

    if (current_size == 0 && (front_block != back_block || front_index != back_index))
    {
        return 4;
    }

    return 0;
}
