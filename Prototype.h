#ifndef PROTOTYPE_H
#define PROTOTYPE_H
template<typename T>
class LinkedList {
private:
    struct Node {
        Node(T data = T(), Node* next = nullptr, Node* prev = nullptr) {
            m_data = data;
            m_next = next;
            m_prev = prev;
        }
        T m_data;
        Node* m_next;
        Node* m_prev;
    };

public:
    class Iterator : public std::iterator<std::bidirectional_iterator_tag,T> {

    public:
        using value = T;
        using referance = T&;
        using pointer = T*;
        explicit Iterator(T* ptr);
        referance operator*() const;
        pointer operator->() const;
        Iterator& operator++();
        Iterator& operator++(int);
        Iterator& operator--();
        Iterator& operator--(int);
        bool operator==(const Iterator& other);
        bool operator!=(const Iterator& other);
        Iterator() : m_ptr(nullptr) {}
        Iterator(Node* obj) : m_ptr(obj) {}
        Iterator(const Iterator& obj) : m_ptr(obj.m_ptr) {}
        Iterator& operator=(const Iterator& obj) {
            m_ptr = obj.m_ptr;
            return *this;
        }
    private:
        friend LinkedList<T>;
        Node* m_ptr;
    };
public:

    LinkedList();
    LinkedList(const LinkedList<T>&);
    LinkedList(LinkedList<T>&&);
    LinkedList(std::initializer_list<T>);
    ~LinkedList();
    template<typename T1>
    friend std::ostream& operator<<(std::ostream&, const LinkedList<T1>&);
    bool operator==(LinkedList<T>&);
    bool operator!=(LinkedList<T>&);
    LinkedList<T>& operator=(const LinkedList<T>&);
    LinkedList<T>& operator=(LinkedList<T>&&);
    bool operator<(const LinkedList<T>&);
    bool operator<=(const LinkedList<T>&);
    bool operator>(const LinkedList<T>&);
    bool operator>=(const LinkedList<T>&);
public:
    Iterator insert(Iterator pos, const T& value);
    Iterator erase(Iterator pos);
    Iterator begin();
    Iterator end();
    int size();
    void sort();
    void clear();
    void unique();
    void reverse();
    void pop_back();
    void pop_front();
    bool empty() const;
    const T& back() const;
    void resize(int index);
    const T& front() const;
    void push_back(T value);
    void push_front(T value);
    void remove(const T& value);
    void swap(LinkedList<T>& obj);
    void merge(LinkedList<T>& obj);
    void insert(int index, T value);
    void assign(int count, const T& value);
private:

    Node* m_head;
    Node* m_tail;
    int m_size;
};
#include "Implimentation.h"
#endif //PROTOTYPE_H
