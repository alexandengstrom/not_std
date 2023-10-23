

template <typename K, typename V>
not_std::unordered_map<K, V>::unordered_map() : data{new KeyValuePair[8]}, current_size{0}, capacity{8}
{
    hash_function = not_std::hash<K>{};
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
        data[i].tombstone = false;
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
            data[index].key = key;
            data[index].value = value;
            data[index].state = SlotState::OCCUPIED;
            current_size++;

            return;
        }

        else if (data[index].state == SlotState::OCCUPIED && data[index].key == key)
        {
            data[index].value = value;
            return;
        }

        index = (index + 1) % capacity;
    }
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
        if (data[index].state == SlotState::OCCUPIED && data[index].key == key)
        {
            return data[index].value;
        }
        else if (data[index].state == SlotState::EMPTY)
        {
            data[index].key = key;
            data[index].state = SlotState::OCCUPIED;
            current_size++;
            return data[index].value;
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
        if (data[index].state == SlotState::OCCUPIED && data[index].key == key)
        {
            return data[index].value;
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
            insert(old_data[i].key, old_data[i].value);
        }
    }

    current_size -= old_size;

    delete[] old_data;
}

template <typename K, typename V>
not_std::unordered_map<K, V>::iterator::iterator(KeyValuePair *ptr, u_int capacity)
    : ptr(ptr), capacity(capacity) {}

template <typename K, typename V>
typename not_std::unordered_map<K, V>::iterator &not_std::unordered_map<K, V>::iterator::operator++()
{
    ++ptr;
    --capacity;

    if (!capacity)
    {
        return *this;
    }

    while (ptr->state != SlotState::OCCUPIED)
    {
        ++ptr;
        --capacity;
    }

    return *this;
}

template <typename K, typename V>
not_std::pair<K, V> &not_std::unordered_map<K, V>::iterator::operator*() const
{
    static not_std::pair<K, V> result;
    result.first = ptr->key;
    result.second = ptr->value;
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
            return iterator(&data[i], capacity);
        }
    }
    return end();
}
template <typename K, typename V>
typename not_std::unordered_map<K, V>::iterator not_std::unordered_map<K, V>::end()
{
    return iterator(&data[capacity]);
}