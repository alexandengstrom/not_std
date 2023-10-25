template <typename K, typename V>
not_std::unordered_map<K, V>::unordered_map() : data{new KeyValuePair[8]}, current_size{0}, capacity{8}
{
    hash_function = not_std::hash<K>{};
}

template <typename K, typename V>
not_std::unordered_map<K, V>::unordered_map(const unordered_map &other)
    : data{new KeyValuePair[other.capacity]}, current_size{other.current_size}, capacity{other.capacity}, hash_function{other.hash_function}
{
    for (not_std::u_int i{0}; i < capacity; ++i)
    {
        data[i] = other.data[i];
    }
}

template <typename K, typename V>
not_std::unordered_map<K, V>::unordered_map(unordered_map &&other)
    : data{other.data}, current_size{other.current_size}, capacity{other.capacity}, hash_function{other.hash_function}
{
    other.data = nullptr;
    other.current_size = 0;
    other.capacity = 0;
}

template <typename K, typename V>
not_std::unordered_map<K, V>::~unordered_map()
{
    delete[] data;
}

template <typename K, typename V>
bool not_std::unordered_map<K, V>::empty() const noexcept
{
    return current_size == 0;
}

template <typename K, typename V>
not_std::u_int not_std::unordered_map<K, V>::size() const noexcept
{
    return current_size;
}

template <typename K, typename V>
void not_std::unordered_map<K, V>::clear()
{
    for (not_std::u_int i{0}; i < capacity; ++i)
    {
        data[i].state = SlotState::EMPTY;
    }

    current_size = 0;
}

template <typename K, typename V>
void not_std::unordered_map<K, V>::insert(const K &key, const V &value)
{
    if (static_cast<float>(current_size) / capacity > LOAD_FACTOR)
    {
        rehash();
    }

    u_int index = hash_function(key) % capacity;

    while (true)
    {
        if (data[index].state == SlotState::EMPTY || data[index].state == SlotState::TOMBSTONED)
        {
            data[index].pair.first = key;
            data[index].pair.second = value;
            data[index].state = SlotState::OCCUPIED;
            current_size++;

            return;
        }

        else if (data[index].state == SlotState::OCCUPIED && data[index].pair.first == key)
        {
            data[index].pair.second = value;
            return;
        }

        index = (index + 1) % capacity;
    }
}

template <typename K, typename V>
not_std::lu_int not_std::unordered_map<K, V>::erase(const K &key)
{
    lu_int index = hash_function(key) % capacity;

    while (data[index].state != SlotState::EMPTY)
    {
        if (data[index].state == SlotState::OCCUPIED && data[index].pair.first == key)
        {
            data[index].state = SlotState::TOMBSTONED;
            --current_size;
            return 1;
        }

        index = (index + 1) % capacity;
    }

    return 0;
}

template <typename K, typename V>
V &not_std::unordered_map<K, V>::operator[](const K &key)
{
    if (static_cast<float>(current_size) / capacity > LOAD_FACTOR)
    {
        rehash();
    }

    u_int index = hash_function(key) % capacity;

    while (true)
    {
        if (data[index].state == SlotState::OCCUPIED && data[index].pair.first == key)
        {
            return data[index].pair.second;
        }
        else if (data[index].state == SlotState::EMPTY)
        {
            data[index].pair.first = key;
            data[index].state = SlotState::OCCUPIED;
            current_size++;
            return data[index].pair.second;
        }

        index = (index + 1) % capacity;
    }
}

template <typename K, typename V>
const V &not_std::unordered_map<K, V>::operator[](const K &key) const
{
    u_int index = hash_function(key) % capacity;
    u_int start_index = index;

    while (true)
    {
        if (data[index].state == SlotState::OCCUPIED && data[index].pair.first == key)
        {
            return data[index].pair.second;
        }

        index = (index + 1) % capacity;

        if (index == start_index)
        {
            // TODO: Create exception
            throw;
        }
    }
}

template <typename K, typename V>
not_std::unordered_map<K, V> &not_std::unordered_map<K, V>::operator=(const unordered_map<K, V> &other)
{
    if (this != &other)
    {
        delete[] data;

        data = new KeyValuePair[other.capacity];
        current_size = other.current_size;
        capacity = other.capacity;
        hash_function = other.hash_function;

        for (not_std::u_int i{0}; i < capacity; ++i)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename K, typename V>
not_std::unordered_map<K, V> &not_std::unordered_map<K, V>::operator=(unordered_map<K, V> &&other)
{
    if (this != &other)
    {
        delete[] data;

        data = other.data;
        current_size = other.current_size;
        capacity = other.capacity;
        hash_function = other.hash_function;

        other.data = nullptr;
        other.current_size = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename K, typename V>
void not_std::unordered_map<K, V>::rehash()
{
    KeyValuePair *old_data{data};
    u_int old_capacity{capacity};
    u_int old_size{current_size};

    capacity *= GROWTH_FACTOR;
    data = new KeyValuePair[capacity];

    for (u_int i{0}; i < old_capacity; ++i)
    {
        if (old_data[i].state == SlotState::OCCUPIED)
        {
            insert(old_data[i].pair.first, old_data[i].pair.second);
        }
    }

    current_size -= old_size;

    delete[] old_data;
}

template <typename K, typename V>
not_std::unordered_map<K, V>::iterator::iterator(KeyValuePair *ptr, KeyValuePair *map_end) : ptr(ptr), map_end(map_end) {}

template <typename K, typename V>
typename not_std::unordered_map<K, V>::iterator &not_std::unordered_map<K, V>::iterator::operator++()
{
    if (ptr >= map_end)
        return *this;

    do
    {
        ++ptr;
    } while (ptr < map_end && ptr->state != SlotState::OCCUPIED);

    return *this;
}

template <typename K, typename V>
not_std::pair<K, V> &not_std::unordered_map<K, V>::iterator::operator*() const
{
    not_std::pair<K, V> &result{ptr->pair};
    return result;
}

template <typename K, typename V>
bool not_std::unordered_map<K, V>::iterator::operator!=(const iterator &other) const
{
    return ptr != other.ptr;
}

template <typename K, typename V>
typename not_std::unordered_map<K, V>::iterator not_std::unordered_map<K, V>::begin()
{
    for (u_int i{0}; i < capacity; ++i)
    {
        if (data[i].state == SlotState::OCCUPIED)
        {
            return iterator(&data[i], &data[capacity]);
        }
    }
    return end();
}

template <typename K, typename V>
typename not_std::unordered_map<K, V>::iterator not_std::unordered_map<K, V>::end()
{
    return iterator(&data[capacity], &data[capacity]);
}