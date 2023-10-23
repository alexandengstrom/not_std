template <typename T1, typename T2>
not_std::pair<T1, T2>::pair() : first{}, second{} {}

template <typename T1, typename T2>
not_std::pair<T1, T2>::pair(const T1 &a, const T2 &b) : first(a), second(b) {}

template <typename T1, typename T2>
not_std::pair<T1, T2> &not_std::pair<T1, T2>::operator=(const not_std::pair<T1, T2> &pair)
{
    if (this != &pair)
    {
        first = pair.first;
        second = pair.second;
    }
    return *this;
}

template <typename T1, typename T2>
bool not_std::pair<T1, T2>::operator==(const not_std::pair<T1, T2> &p) const
{
    return first == p.first && second == p.second;
}

template <typename T1, typename T2>
bool not_std::pair<T1, T2>::operator!=(const not_std::pair<T1, T2> &other) const
{
    return !(*this == other);
}

template <typename T1, typename T2>
bool not_std::pair<T1, T2>::operator<(const not_std::pair<T1, T2> &other) const
{
    return first < other.first || (!(other.first < first) && second < other.second);
}