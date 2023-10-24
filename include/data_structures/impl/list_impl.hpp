template <typename T>
not_std::list<T>::Node::Node(T &v) : next(nullptr), prev(nullptr), value(v) {}

template <typename T>
not_std::list<T>::Node::Node(T &&v) : next(nullptr), prev(nullptr), value(v) {}

template <typename T>
not_std::list<T>::Node::Node() : next(nullptr), prev(nullptr) {}

template <typename T>
not_std::list<T>::Node::~Node()
{
    delete next;
}

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
not_std::list<T>::~list()
{
    delete head;
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