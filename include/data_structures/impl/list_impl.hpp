template <typename T>
not_std::list<T>::Node::Node(const T &v) : next(nullptr), prev(nullptr), value(v) {}

template <typename T>
not_std::list<T>::Node::Node(T &&v) : next(nullptr), prev(nullptr), value(v) {}

template <typename T>
not_std::list<T>::Node::Node() : next(nullptr), prev(nullptr) {}

template <typename T>
not_std::list<T>::Node::~Node() {}

template <typename T>
not_std::list<T>::list() : current_size(0)
{
    head = new Node{};
    tail = new Node{};
    head->next = tail;
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
}

template <typename T>
not_std::list<T>::list(const not_std::list<T> &other) : current_size(0)
{
    head = new Node{};
    tail = new Node{};
    head->next = tail;
    tail->prev = head;

    Node *temp = other.head->next;
    while (temp != other.tail)
    {
        push_back(temp->value);
        temp = temp->next;
    }
}

template <typename T>
not_std::list<T>::list(not_std::list<T> &&other) noexcept : head(other.head), tail(other.tail), current_size(other.current_size)
{
    other.head = new Node{};
    other.tail = new Node{};
    other.head->next = other.tail;
    other.tail->prev = other.head;
    other.current_size = 0;
}

template <typename T>
not_std::list<T>::~list()
{
    Node *current_node{head};

    while (current_node->next)
    {
        Node *tmp{current_node};
        current_node = current_node->next;
        delete tmp;
    }
    delete current_node;
}

template <typename T>
not_std::list<T> &not_std::list<T>::operator=(const not_std::list<T> &other)
{
    if (this != &other)
    {
        while (!empty())
        {
            pop_back();
        }

        Node *temp = other.head->next;
        while (temp != other.tail)
        {
            push_back(temp->value);
            temp = temp->next;
        }
    }
    return *this;
}

template <typename T>
not_std::list<T> &not_std::list<T>::operator=(not_std::list<T> &&other) noexcept
{
    if (this != &other)
    {
        delete head;
        delete tail;

        head = other.head;
        tail = other.tail;
        current_size = other.current_size;

        other.head = new Node{};
        other.tail = new Node{};
        other.head->next = other.tail;
        other.tail->prev = other.head;
        other.current_size = 0;
    }
    return *this;
}

template <typename T>
T &not_std::list<T>::front()
{
    return head->next->value;
}

template <typename T>
T &not_std::list<T>::back()
{
    return tail->prev->value;
}

template <typename T>
bool not_std::list<T>::empty() const noexcept
{
    return head->next == tail;
}

template <typename T>
not_std::u_int not_std::list<T>::size() const noexcept
{
    return current_size;
}

template <typename T>
void not_std::list<T>::push_back(const T &value)
{
    Node *new_node{new Node{value}};
    new_node->next = tail;
    new_node->prev = tail->prev;
    tail->prev->next = new_node;
    tail->prev = new_node;
    current_size++;
}

template <typename T>
void not_std::list<T>::push_back(T &&value)
{
    Node *new_node{new Node{value}};
    new_node->next = tail;
    new_node->prev = tail->prev;
    tail->prev->next = new_node;
    tail->prev = new_node;
    current_size++;
}

template <typename T>
void not_std::list<T>::push_front(const T &value)
{
    Node *new_node{new Node{value}};
    new_node->next = head->next;
    new_node->next->prev = new_node;
    new_node->prev = head;
    head->next = new_node;
    current_size++;
}

template <typename T>
void not_std::list<T>::push_front(T &&value)
{
    Node *new_node{new Node{value}};
    new_node->next = head->next;
    new_node->next->prev = new_node;
    new_node->prev = head;
    head->next = new_node;
    current_size++;
}

template <typename T>
void not_std::list<T>::pop_back()
{
    Node *to_delete{tail->prev};
    to_delete->prev->next = tail;
    tail->prev = to_delete->prev;
    to_delete->next = nullptr;
    delete to_delete;
}

template <typename T>
void not_std::list<T>::pop_front()
{
    Node *to_delete{head->next};
    to_delete->next->prev = head;
    head->next = to_delete->next;
    to_delete->next = nullptr;
    delete to_delete;
}

template <typename T>
not_std::list<T>::iterator::iterator(Node *node) : current_node{node} {}

template <typename T>
T &not_std::list<T>::iterator::operator*()
{
    return current_node->value;
}

template <typename T>
typename not_std::list<T>::iterator &not_std::list<T>::iterator::operator++()
{
    current_node = current_node->next;
    return *this;
}

template <typename T>
bool not_std::list<T>::iterator::operator!=(const not_std::list<T>::iterator &other) const
{
    return current_node != other.current_node;
}

template <typename T>
typename not_std::list<T>::iterator not_std::list<T>::begin()
{
    return iterator(head->next);
}

template <typename T>
typename not_std::list<T>::iterator not_std::list<T>::end()
{
    return iterator(tail);
}

template <typename T>
not_std::list<T>::reverse_iterator::reverse_iterator(Node *node) : current_node{node} {}

template <typename T>
T &not_std::list<T>::reverse_iterator::operator*()
{
    return current_node->value;
}

template <typename T>
typename not_std::list<T>::reverse_iterator &not_std::list<T>::reverse_iterator::operator++()
{
    current_node = current_node->prev;
    return *this;
}

template <typename T>
bool not_std::list<T>::reverse_iterator::operator!=(const not_std::list<T>::reverse_iterator &other) const
{
    return current_node != other.current_node;
}

template <typename T>
typename not_std::list<T>::reverse_iterator not_std::list<T>::rbegin()
{
    return reverse_iterator(tail->prev);
}

template <typename T>
typename not_std::list<T>::reverse_iterator not_std::list<T>::rend()
{
    return reverse_iterator(head);
}
