template<typename T>
void LinkedList<T>::assign(int count, const T& value)
{
    if (m_head != nullptr && count > 0) {
        clear();
        m_head = nullptr;
    }
    for (int i = 0; i < count; ++i) {
        push_back(value);
    }

}

template<typename T>
const T& LinkedList<T>::front() const
{
    return m_head->m_data;
}

template<typename T>
const T& LinkedList<T>::back() const
{
    return m_tail->m_data;
}

template<typename T>
void LinkedList<T>::unique()
{
    Node* new_ptr = m_head;
    Node* ptr = nullptr;
    while (new_ptr != m_tail) {
        if (new_ptr->m_data == new_ptr->m_next->m_data) {
            ptr = new_ptr->m_next;
            if (ptr == m_tail) {
                m_tail = m_tail->m_prev;
                m_tail->m_next = nullptr;
                delete ptr;
                break;
            }
            new_ptr->m_next = ptr->m_next;
            ptr->m_next->m_prev = ptr->m_prev;
            ptr->m_next = nullptr;
            ptr->m_prev = nullptr;
            delete ptr;
        } else {
            new_ptr = new_ptr->m_next;
        }
    }
    ptr = nullptr;
    new_ptr = nullptr;
}

template<typename T>
void LinkedList<T>::reverse()
{
    if (m_head == nullptr || m_size == 1) {
        return;
    } else {
        Node* new_node = m_head;
        Node* node = m_tail;
        Node* end = nullptr;
        while (new_node != node) {
            m_head = m_head->m_next;
            m_head->m_prev = nullptr;
            new_node->m_next = nullptr;
            if (m_tail->m_next == nullptr) {
                m_tail->m_next = new_node;
                new_node->m_prev = m_tail;
                end = new_node;
            } else {
                m_tail->m_next->m_prev = new_node;
                new_node->m_prev = m_tail;
                new_node->m_next = m_tail->m_next;
                m_tail->m_next = new_node;
            }
            new_node = nullptr;
            new_node = m_head;
        }
        m_tail = end;
        end = nullptr;
        new_node = nullptr;
        node = nullptr;
    }
}

template<typename T>
void LinkedList<T>::remove(const T& value)
{
    Node* tmp = m_head;
    Node* d_tmp = m_head;
    while (tmp != m_tail) {
        while (tmp == m_head && tmp->m_data == value) {
            tmp = tmp->m_next;
            m_head = tmp;
            tmp->m_prev = nullptr;
            d_tmp->m_next = nullptr;
            delete d_tmp;
        }
         if(tmp->m_data == value) {
            d_tmp = tmp->m_prev;
            tmp->m_prev->m_next = tmp->m_next;
            tmp->m_next->m_prev = tmp->m_prev;
            tmp->m_next = nullptr;
            tmp->m_prev = nullptr;
            delete tmp;
            tmp = d_tmp;
        } else {
        tmp = tmp->m_next;
        }
    }
    if (m_tail->m_data == value) {
        tmp = m_tail;
        m_tail = m_tail->m_prev;
        m_tail->m_next = nullptr;
        tmp->m_prev = nullptr;
    }
    tmp = nullptr;
    d_tmp = nullptr;
}

template<typename T>
void LinkedList<T>::merge(LinkedList<T>& obj)
{
    if (obj.m_head == nullptr) {
        return;
    }
    if (m_head == nullptr) {
        m_head = obj.m_head;
        m_tail = obj.m_tail;
    } else {
        Node* new_ptr = m_head;
        Node* ptr = obj.m_head;
        while (new_ptr != nullptr && ptr != nullptr) {
            if (new_ptr->m_data > ptr->m_data) {
                obj.m_head = obj.m_head->m_next;
                if (new_ptr == m_head) {
                    new_ptr->m_prev = ptr;
                    ptr->m_next = new_ptr;
                    m_head = ptr;
                } else {
                    new_ptr->m_prev->m_next = ptr;
                    ptr->m_prev = new_ptr->m_prev;
                    ptr->m_next = new_ptr;
                    new_ptr->m_prev = ptr;
                }
                ptr = obj.m_head;
                if (ptr != nullptr) {
                    ptr->m_prev = nullptr;
                }
            } else {
                new_ptr = new_ptr->m_next;
            }
        }
        if (new_ptr == nullptr && ptr != nullptr) {
            m_tail->m_next = ptr;
            ptr->m_prev = m_tail;
            m_tail = obj.m_tail;
        }
        new_ptr = nullptr;
        ptr = nullptr;
    }
    obj.m_head = nullptr;
    obj.m_tail = nullptr;
}

template<typename T>
void LinkedList<T>::sort()
{
    if (m_head == nullptr) {
        return;
    }
    if (m_head == m_tail) {
        return;
    }
    Node* new_ptr = m_head;
    T item{};
    int flag = 0;
    do
      {
        flag = 0;
        while (new_ptr -> m_next != nullptr)
        {
            if (new_ptr -> m_data > new_ptr -> m_next -> m_data)
            {
                item = new_ptr -> m_data;
                new_ptr -> m_data = new_ptr -> m_next -> m_data;
                new_ptr -> m_next -> m_data = item;
                flag = 1;
            }
            new_ptr = new_ptr -> m_next;
        }
        new_ptr = m_head;
       } while (flag);
    new_ptr = nullptr;
}

template<typename T>
void LinkedList<T>::swap(LinkedList<T>& obj)
{
    Node* new_ptr = obj.m_head;
    Node* new_pt = obj.m_tail;
    obj.m_head = m_head;
    obj.m_tail = m_tail;
    m_head = new_ptr;
    m_tail = new_pt;
    new_ptr = nullptr;
    new_pt = nullptr;
}

template<typename T>
void LinkedList<T>::resize(int index)
{
    int new_size = 0;
    if (m_size > index) {
        new_size = m_size;
    }
    if (m_size < index) {
        new_size = m_size;
    }
    while (index < new_size) {
        pop_back();
        --new_size;
    }
    while (index > new_size) {
        push_back(0);
        ++new_size;
    }
}

template<typename T>
void LinkedList<T>::pop_front()
{
    if (m_head == m_tail) {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
        return;
    }
    Node* new_ptr = m_head;
    m_head = new_ptr -> m_next;
    m_head -> m_prev = nullptr;
    new_ptr = nullptr;
    --m_size;
    delete new_ptr;
    return;

}

template<typename T>
void LinkedList<T>::pop_back()
{
   if (m_head == m_tail) {
          delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
        return;
    }
    Node* new_ptr = m_tail;
    m_tail = new_ptr -> m_prev;
    m_tail -> m_next = nullptr;
    new_ptr -> m_prev = nullptr;
    --m_size;
    delete new_ptr;
    return;
}

template<typename T>
bool LinkedList<T>::empty() const
{
    if (m_head) {
        return false;
    }
    return true;
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::erase(Iterator pos)
{
    if (m_head == nullptr) {
        return pos;
    }
    Node* new_ptr = pos.m_ptr;
     if (new_ptr == m_head && new_ptr == m_tail) {
          delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
        return pos;
    }
    if (pos.m_ptr -> m_prev == nullptr && pos.m_ptr -> m_next != nullptr) {
        pop_front();
        return pos;
    }
    if (pos.m_ptr == m_tail) {
        pop_back();
        return pos;
    }
    new_ptr -> m_prev -> m_next = new_ptr -> m_next;
    new_ptr -> m_next -> m_prev = new_ptr -> m_prev;
    new_ptr -> m_next = nullptr;
    new_ptr -> m_prev = nullptr;
    delete new_ptr;
    --m_size;
    return pos;

}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::insert(Iterator pos, const T& value)
{
    Node* new_ptr = new Node(value);
            new_ptr -> m_next = pos.m_ptr -> m_next;
            new_ptr -> m_next -> m_prev = new_ptr;
            new_ptr -> m_prev = pos.m_ptr;
            pos.m_ptr -> m_next = new_ptr;
            ++m_size;
    return pos;
}
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    return m_head;
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    return nullptr;
}

template<typename T>
void LinkedList<T>::insert(int index, T value)
{
    if (index == 0) {
        push_front(value);
        return;
    }
    if (index == m_size) {
        push_back(value);
        return;
    }
}

template<typename T>
bool LinkedList<T>::operator<(const LinkedList<T>& obj) { //const
    if (this -> m_size < obj.m_size) {
        return true;
    }
    return false;
}

template<typename T>
bool LinkedList<T>::operator<=(const LinkedList<T>& obj)
{
    if (this -> m_size <= obj.m_size) {
        return true;
    }
    return false;
}

template<typename T>
bool LinkedList<T>::operator>(const LinkedList<T>& obj)
{
     if (this -> m_size > obj.m_size) {
        return true;
     }
     return false;
}

template<typename T>
bool LinkedList<T>::operator>=(const LinkedList<T>& obj)
{
    if (this -> m_size >= obj.m_size) {
        return true;
    }
    return false;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& obj)
{
    if (this -> m_head != nullptr) {
        clear();
    }
    this -> m_head = obj.m_head;
    this -> m_tail = obj.m_tail;
    obj.m_head = nullptr;
    obj.m_tail = nullptr;
    return *this;
}

template<typename T>
void LinkedList<T>::clear()
{
    if (m_head == nullptr) {
        return;
    }
    Node* tmp = nullptr;
    while (m_head) {
        tmp = m_head;
        m_head = m_head -> m_next;
        delete tmp;
    }
    m_size = 0;
    m_head = nullptr;
}

template<typename T>
int LinkedList<T>::size()
{
    return m_size;
}
template<typename T>
bool LinkedList<T>::operator==(LinkedList<T>& obj)
{
    if(this->m_size != obj.m_size) {
        return false;
    }
    Node* tmp = this->m_head;
    Node* tmp1 = obj.m_head;
    while (tmp != nullptr) {
        if (tmp -> m_data != tmp1 -> m_data) {
            return false;
        }
        tmp = tmp->m_next;
        tmp1 = tmp1->m_next;
    }
    return true;
}
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& obj)
{
    if (this -> m_head != nullptr) {
         clear();
    }
    Node* ptr = obj.m_head;
    while (ptr != nullptr) {
        push_back(ptr -> m_data);
        ptr = ptr -> m_next;
    }
    return *this;
}

template<typename T>
bool LinkedList<T>::operator!=(LinkedList<T>& obj)
{
    return !(this->m_size == obj.m_size);
}
template<typename T>
std::ostream& operator<<(std::ostream& cout, const LinkedList<T>& obj)
{
    typename LinkedList<T>::template Node* tmp = obj.m_head;
    while (tmp != nullptr) {
        cout << tmp -> m_data << " ";
        tmp = tmp -> m_next;
    }
    return cout;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node* tmp = nullptr;
	while (m_head) {
		tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
	m_size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> obj)
{
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
    for (auto it = obj.begin(); it != obj.end(); ++it) {
        push_back(*it);
    }
}

template<typename T>
void LinkedList<T>::push_back(T value)
{
    if(m_head == nullptr) {
        m_head = new Node(value);
        m_tail = m_head;
    } else {
        Node* new_ptr = new Node(value);
        Node* ptr = m_tail;
        ptr->m_next = new_ptr;
        new_ptr -> m_prev = ptr;
        m_tail = new_ptr;
    }
    ++m_size;
}

template<typename T>
void LinkedList<T>::push_front(T value)
{
    Node* new_node = new Node(value);
    if(m_head == nullptr) {
        m_head = new_node;
        m_tail = m_head;
    } else {
        new_node -> m_next = m_head;
        m_head -> m_prev = new_node;
        m_head = new_node;
    }
    ++m_size;
}

template<typename T>
LinkedList<T>::LinkedList()
{
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& obj)
{
    if(obj.m_head == nullptr) {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    } else {
    Node* tmp = obj.m_head;
    m_head = new Node(tmp->m_data, nullptr , nullptr);
    tmp = tmp->m_next;
    Node* tmp2 = m_head;
    while(tmp != nullptr) {
        tmp2->m_next = new Node;
        tmp2->m_next->m_prev = tmp2;
        tmp2 = tmp2->m_next;
        tmp2->m_data = tmp->m_data;
        tmp = tmp->m_next;
    }
    tmp2->m_next = nullptr;
    m_tail = tmp2;
    }
    m_size = obj.m_size;
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& obj) :
    m_head(obj.m_head),
    m_tail(obj.m_tail),
    m_size(obj.m_size)
{
    obj.m_head = nullptr;
    obj.m_tail = nullptr;
    obj.m_size = 0;
}

template<typename T>
LinkedList<T>::Iterator::Iterator(T* ptr) : m_ptr(ptr) {}

template<typename T>
typename LinkedList<T>::Iterator::referance LinkedList<T>::Iterator::operator*() const
{
    return *m_ptr;
}

template<typename T>
typename LinkedList<T>::Iterator::pointer LinkedList<T>::Iterator::operator->() const
{
    return (&(m_ptr -> m_data));
}

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++()
{
    m_ptr = m_ptr->m_next;
    return *this;
}

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++(int)
{
    Iterator* tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--()
{
    m_ptr = m_ptr-> m_prev;
    return *this;
}

template<typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--(int)
{
    Iterator* tmp = *this;
    --(*this);
    return *this;
}

template<typename T>
bool LinkedList<T>::Iterator::operator==(const Iterator& other)
{
    return m_ptr == other.m_ptr;
}

template<typename T>
bool LinkedList<T>::Iterator::operator!=(const Iterator& other)
{
    return m_ptr != other.m_ptr;
}
