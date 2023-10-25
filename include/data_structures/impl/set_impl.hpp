template <typename T>
not_std::set<T>::set() : root{nullptr}, current_size{0} {}

template <typename T>
not_std::set<T>::~set()
{
    // TODO
}

template <typename T>
void not_std::set<T>::insert(const T &value)
{
    current_size++;

    if (!root)
    {
        root = create_node(value, BLACK);
        return;
    }

    Node *parent{nullptr};
    Node *current{root};
    while (current)
    {
        parent = current;
        if (value < current->value)
        {
            current = current->left;
        }
        else if (value > current->value)
        {
            current = current->right;
        }
        else
        {
            current_size--;
            return;
        }
    }

    Node *new_node{create_node(value, RED, parent)};
    if (value < parent->value)
    {
        parent->left = new_node;
    }
    else
    {
        parent->right = new_node;
    }

    fix_violations(new_node);
}

template <typename T>
void not_std::set<T>::erase(const T &value)
{
    remove_node(value);
}

template <typename T>
bool not_std::set<T>::contains(const T &value)
{
    return search(value) != nullptr;
}

template <typename T>
bool not_std::set<T>::empty() const
{
    return root == nullptr;
}

template <typename T>
not_std::u_int not_std::set<T>::size() const
{
    return current_size;
}

template <typename T>
typename not_std::set<T>::Node *not_std::set<T>::search(const T &value)
{
    Node *current{root};
    while (current != nullptr)
    {
        if (value < current->value)
            current = current->left;
        else if (value > current->value)
            current = current->right;
        else
            return current;
    }
    return nullptr;
}

template <typename T>
typename not_std::set<T>::Node *not_std::set<T>::create_node(const T &value, Color color, Node *parent, Node *left, Node *right)
{
    Node *new_node{new Node{}};
    new_node->value = value;
    new_node->color = color;
    new_node->parent = parent;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

template <typename T>
void not_std::set<T>::rotate_left(Node *x)
{
    Node *y{x->right};
    x->right = y->left;

    if (y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

template <typename T>
void not_std::set<T>::rotate_right(Node *y)
{
    Node *x{y->left};
    y->left = x->right;

    if (x->right != nullptr)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

template <typename T>
void not_std::set<T>::fix_violations(Node *inserted)
{
    Node *current{inserted};
    Node *parent_node{nullptr};
    Node *grandparent_node{nullptr};

    while ((current != root) && (current->color != BLACK) && (current->parent->color == RED))
    {
        parent_node = current->parent;
        grandparent_node = parent_node->parent;

        if (parent_node == grandparent_node->left)
        {
            Node *uncle_node = grandparent_node->right;

            if (uncle_node && uncle_node->color == RED)
            {
                grandparent_node->color = RED;
                parent_node->color = BLACK;
                uncle_node->color = BLACK;
                current = grandparent_node;
            }
            else
            {
                if (current == parent_node->right)
                {
                    rotate_left(parent_node);
                    current = parent_node;
                    parent_node = current->parent;
                }

                parent_node->color = BLACK;
                grandparent_node->color = RED;
                rotate_right(grandparent_node);
            }
        }
        else
        {
            Node *uncle_node = grandparent_node->left;

            if (uncle_node && uncle_node->color == RED)
            {
                grandparent_node->color = RED;
                parent_node->color = BLACK;
                uncle_node->color = BLACK;
                current = grandparent_node;
            }
            else
            {
                if (current == parent_node->left)
                {
                    rotate_right(parent_node);
                    current = parent_node;
                    parent_node = current->parent;
                }

                parent_node->color = BLACK;
                grandparent_node->color = RED;
                rotate_left(grandparent_node);
            }
        }
    }

    root->color = BLACK;
}

template <typename T>
typename not_std::set<T>::Node *not_std::set<T>::remove_node(const T &value)
{
    Node *node{search(value)};
    if (!node)
    {
        return nullptr;
    }

    current_size--;

    Node *x, *y;

    if (node->left == nullptr || node->right == nullptr)
    {
        y = node;
    }
    else
    {
        y = node->right;
        while (y->left != nullptr)
            y = y->left;
    }

    if (y->left != nullptr)
        x = y->left;
    else
        x = y->right;

    if (x != nullptr)
        x->parent = y->parent;

    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if (y != node)
        node->value = y->value;

    if (y->color == BLACK)
        fix_double_black(x);

    delete y;
    return node;
}

template <typename T>
void not_std::set<T>::fix_double_black(Node *x)
{
    if (!x || x == root)
        return;

    Node *sibling{nullptr};
    Node *parent{x->parent};
    if (x == parent->left)
    {
        sibling = parent->right;
    }
    else
    {
        sibling = parent->left;
    }

    if (sibling == nullptr)
    {
        fix_double_black(parent);
    }
    else
    {
        if (sibling->color == RED)
        {
            parent->color = RED;
            sibling->color = BLACK;
            if (sibling->is_on_left())
            {
                rotate_right(parent);
            }
            else
            {
                rotate_left(parent);
            }
            fix_double_black(x);
        }
        else
        {
            if (sibling->has_red_child())
            {
                if (sibling->left != nullptr && sibling->left->color == RED)
                {
                    if (sibling->is_on_left())
                    {
                        sibling->left->color = sibling->color;
                        sibling->color = parent->color;
                        rotate_right(parent);
                    }
                    else
                    {
                        sibling->left->color = parent->color;
                        rotate_right(sibling);
                        rotate_left(parent);
                    }
                }
                else
                {
                    if (sibling->is_on_left())
                    {
                        sibling->right->color = parent->color;
                        rotate_left(sibling);
                        rotate_right(parent);
                    }
                    else
                    {
                        sibling->right->color = sibling->color;
                        sibling->color = parent->color;
                        rotate_left(parent);
                    }
                }
                parent->color = BLACK;
            }
            else
            {
                sibling->color = RED;
                if (parent->color == BLACK)
                    fix_double_black(parent);
                else
                    parent->color = BLACK;
            }
        }
    }
}

template <typename T>
bool not_std::set<T>::Node::has_red_child()
{
    return (left && left->color == RED) || (right && right->color == RED);
}

template <typename T>
bool not_std::set<T>::Node::is_on_left()
{
    return parent && this == parent->left;
}

template <typename T>
not_std::set<T>::iterator::iterator(Node *start) : ptr{start} {}

template <typename T>
not_std::set<T>::iterator::iterator() : ptr{nullptr} {}

template <typename T>
T &not_std::set<T>::iterator::operator*()
{
    return ptr->value;
}

template <typename T>
typename not_std::set<T>::iterator &not_std::set<T>::iterator::operator++()
{
    if (ptr)
    {
        if (ptr->right)
        {
            ptr = ptr->right;
            while (ptr->left)
            {
                ptr = ptr->left;
            }
        }
        else
        {
            Node *tmp{ptr->parent};
            while (tmp && ptr == tmp->right)
            {
                ptr = tmp;
                tmp = tmp->parent;
            }
            ptr = tmp;
        }
    }
    return *this;
}

template <typename T>
bool not_std::set<T>::iterator::operator!=(const not_std::set<T>::iterator &other)
{
    return ptr != other.ptr;
}

template <typename T>
typename not_std::set<T>::iterator not_std::set<T>::begin()
{
    Node *node = root;
    while (node && node->left)
    {
        node = node->left;
    }
    return iterator(node);
}

template <typename T>
typename not_std::set<T>::iterator not_std::set<T>::end()
{
    return iterator();
}

template <typename T>
not_std::set<T>::reverse_iterator::reverse_iterator(Node *start) : ptr{start} {}

template <typename T>
not_std::set<T>::reverse_iterator::reverse_iterator() : ptr{nullptr} {}

template <typename T>
T &not_std::set<T>::reverse_iterator::operator*()
{
    return ptr->value;
}

template <typename T>
typename not_std::set<T>::reverse_iterator &not_std::set<T>::reverse_iterator::operator++()
{
    if (ptr)
    {
        if (ptr->left)
        {
            ptr = ptr->left;
            while (ptr->right)
            {
                ptr = ptr->right;
            }
        }
        else
        {
            Node *tmp{ptr->parent};
            while (tmp && ptr == tmp->left)
            {
                ptr = tmp;
                tmp = tmp->parent;
            }
            ptr = tmp;
        }
    }
    return *this;
}

template <typename T>
bool not_std::set<T>::reverse_iterator::operator!=(const not_std::set<T>::reverse_iterator &other)
{
    return ptr != other.ptr;
}

template <typename T>
typename not_std::set<T>::reverse_iterator not_std::set<T>::rbegin()
{
    Node *node = root;
    while (node && node->right)
    {
        node = node->right;
    }
    return reverse_iterator(node);
}

template <typename T>
typename not_std::set<T>::reverse_iterator not_std::set<T>::rend()
{
    return reverse_iterator();
}

template <typename T>
std::string not_std::set<T>::print_tree() const
{
    std::string result;
    if (root != nullptr)
    {
        result = print_tree(root, 0);
    }
    return result;
}

template <typename T>
std::string not_std::set<T>::print_tree(Node *node, int depth) const
{
    std::string result;
    if (node != nullptr)
    {
        result += print_tree(node->right, depth + 1);

        if (node->right != nullptr)
        {
            result += indent(depth) + " /\n";
        }

        result += indent(depth) + std::to_string(node->value) + (node->color == RED ? "(R)" : "(B)") + "\n";

        if (node->left != nullptr)
        {
            result += indent(depth) + " \\\n";
        }

        result += print_tree(node->left, depth + 1);
    }
    return result;
}

template <typename T>
std::string not_std::set<T>::indent(int depth) const
{
    std::string result;
    for (int i = 0; i < depth; i++)
    {
        result += "    ";
    }
    return result;
}
