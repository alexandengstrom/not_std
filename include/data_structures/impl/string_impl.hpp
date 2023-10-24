

not_std::string::string() : data{nullptr}, current_size{0}, capacity{0} {}

not_std::string::string(const char *cstr) : data(nullptr), current_size(0), capacity(0)
{
    const char *start = cstr;
    while (*cstr)
    {
        ++cstr;
    }

    u_int new_size = cstr - start;

    reallocate(new_size);
    for (lu_int i{0}; i < new_size; ++i)
    {
        data[i] = start[i];
    }
    current_size = new_size;
    data[current_size] = '\0';
}

not_std::string::~string()
{
    delete[] data;
}

not_std::string::string(const not_std::string &other) : data(nullptr), current_size(other.current_size), capacity(other.capacity)
{
    data = new char[capacity];
    for (lu_int i = 0; i < current_size; ++i)
    {
        data[i] = other.data[i];
    }
}

not_std::string::string(not_std::string &&other) noexcept : data(other.data), current_size(other.current_size), capacity(other.capacity)
{
    other.data = nullptr;
    other.current_size = 0;
    other.capacity = 0;
}

not_std::string &not_std::string::operator=(const not_std::string &other)
{
    if (this != &other)
    {
        delete[] data;

        current_size = other.current_size;
        capacity = other.capacity;
        data = new char[capacity];
        for (lu_int i = 0; i < current_size; ++i)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

not_std::string &not_std::string::operator=(not_std::string &&other) noexcept
{
    if (this != &other)
    {
        delete[] data;

        data = other.data;
        current_size = other.current_size;
        capacity = other.capacity;

        other.data = nullptr;
        other.current_size = 0;
        other.capacity = 0;
    }
    return *this;
}

char &not_std::string::operator[](lu_int pos)
{
    return data[pos];
}

const char &not_std::string::operator[](lu_int pos) const
{
    return data[pos];
}

bool not_std::string::operator==(const not_std::string &other) const
{
    if (this->current_size != other.current_size)
        return false;

    for (lu_int i = 0; i < this->current_size; ++i)
    {
        if (this->data[i] != other.data[i])
            return false;
    }

    return true;
}

bool not_std::string::operator==(const char *cstr) const
{
    const char *s1 = this->data;
    const char *s2 = cstr;

    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return false;
        s1++;
        s2++;
    }

    return *s1 == *s2;
}

bool not_std::string::operator!=(const not_std::string &other) const
{
    return !(*this == other);
}

bool not_std::string::operator!=(const char *cstr) const
{
    return !(*this == cstr);
}

not_std::string &not_std::string::operator+=(const not_std::string &other)
{
    lu_int new_size = current_size + other.current_size;

    if (new_size >= capacity)
    {
        reallocate(new_size);
    }

    for (lu_int i = 0; i < other.current_size; ++i)
    {
        data[current_size + i] = other.data[i];
    }

    current_size = new_size;
    data[current_size] = '\0';

    return *this;
}

not_std::string &not_std::string::operator+=(const char *other)
{
    lu_int rhs_length = 0;
    const char *temp = other;
    while (*temp++)
    {
        ++rhs_length;
    }

    lu_int new_size = current_size + rhs_length;

    if (new_size >= capacity)
    {
        reallocate(new_size);
    }

    for (lu_int i = 0; i < rhs_length; ++i)
    {
        data[current_size + i] = other[i];
    }

    current_size = new_size;
    data[current_size] = '\0';

    return *this;
}

not_std::lu_int not_std::string::length() const noexcept
{
    return current_size;
}

bool not_std::string::empty() const noexcept
{
    return current_size == 0;
}

void not_std::string::clear()
{
    current_size = 0;
}

char not_std::string::at(u_int pos) const
{
    return data[pos];
}

void not_std::string::push_back(char c)
{
    if (current_size + 1 >= capacity)
    {
        reallocate(current_size + 1);
    }
    data[current_size++] = c;
    data[current_size] = '\0';
}

inline std::ostream &operator<<(std::ostream &out, const not_std::string &str)
{
    for (not_std::lu_int i = 0; i < str.length(); ++i)
    {
        out << str.at(i);
    }
    return out;
}

void not_std::string::reallocate(u_int new_size)
{
    lu_int new_capacity = (capacity == 0) ? 1 : capacity * 2;
    while (new_capacity <= new_size)
    {
        new_capacity *= 2;
    }

    char *new_data = new char[new_capacity + 1];

    if (data)
    {
        for (lu_int i = 0; i < current_size; ++i)
        {
            new_data[i] = data[i];
        }
        delete[] data;
    }

    data = new_data;
    capacity = new_capacity;
}
