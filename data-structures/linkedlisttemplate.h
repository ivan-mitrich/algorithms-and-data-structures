#ifndef LINKEDLISTTEMPLATE_H
#define LINKEDLISTTEMPLATE_H
#include <cstddef>
#include <iostream>

struct Point {
    int x, y;
    Point(int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
};
bool operator==(const Point& p1, const Point& p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "{" << p.x << ", " << p.y << "}";
    return os;
}

template <class T>
struct Link {
    T value;
    Link* next;
    Link* prev;
    Link(T v = T(), Link* n = nullptr, Link* p = nullptr) : value(v), next(n), prev(p) {}
};

template <class T>
class LinkedListTemplate
{
public:
    LinkedListTemplate() : head_(nullptr), size_(0) {}
    void pushBack(const T& v);
    void pushFront(const T& v);
    Link<T>* insert(std::size_t n, const T& v); //insertion before n-th element. return inserted
    Link<T>* add(std::size_t n, const T& v); //insertion after n-th element. return inserted
    Link<T>* advance(std::size_t n) const; //return n-th
    Link<T>* find(const T& v) const;
    Link<T>* erase(std::size_t n); // return element next to erased
    int size() const { return size_; }
    Link<T>* head() const { return head_; }
    Link<T>* tail() const { return advance(size_-1); }
private:
    Link<T>* head_;
    std::size_t size_;
};

template<class T>
void LinkedListTemplate<T>::pushBack(const T& v)
{
    auto newItem = new Link<T>(v);
    auto tailItem = tail();
    if(head_ == nullptr)
    {
        head_ = newItem;
    }
    else {
        tailItem->next = newItem;
        newItem->prev = tailItem;
        tailItem = newItem;
    }
    ++size_;
}

template<class T>
void LinkedListTemplate<T>::pushFront(const T &v)
{
    auto newItem = new Link<T>(v);
    if(head_ == nullptr)
    {
        head_ = newItem;
    }
    else {
        head_->prev = newItem;
        newItem->next = head_;
        head_ = newItem;
    }
    ++size_;
}

template<class T>
Link<T> *LinkedListTemplate<T>::insert(std::size_t n, const T &v)
{
    Link<T>* newItem = nullptr;
    if(head_ == nullptr)
    {
        newItem = new Link<T>(v);
        head_ = newItem;
    }
    else {
        auto item = advance(n);
        if(item == nullptr)
            return nullptr;
        newItem = new Link<T>(v);
        auto prevItem = item->prev;
        item->prev = newItem;
        newItem->next = item;
        newItem->prev = prevItem;
        if(prevItem != nullptr)
            prevItem->next = newItem;
        if(item == head_)
            head_ = newItem;
    }
    ++size_;
    return newItem;
}

template<class T>
Link<T> *LinkedListTemplate<T>::add(std::size_t n, const T &v)
{
    Link<T>* newItem = nullptr;
    if(head_ == nullptr)
    {
        newItem = new Link<T>(v);
        head_ = newItem;
    }
    else {
        auto item = advance(n);
        if(item == nullptr)
            return nullptr;
        newItem = new Link<T>(v);
        auto nextItem = item->next;
        item->next = newItem;
        newItem->prev = item;
        newItem->next = nextItem;
        if(nextItem != nullptr)
            nextItem->prev = newItem;
    }
    ++size_;
    return newItem;
}

template<class T>
Link<T> *LinkedListTemplate<T>::advance(std::size_t n) const
{
    auto currentItem = head_;
    while (n > 0 && currentItem != nullptr) {
        currentItem = currentItem->next;
        --n;
    }
    while (n < 0 && currentItem != nullptr) {
        currentItem = currentItem->prev;
        ++n;
    }
    return currentItem;
}

template<class T>
Link<T> *LinkedListTemplate<T>::find(const T &v) const
{
    auto currentItem = head_;
    while (currentItem != nullptr && currentItem->value != v) {
        currentItem = currentItem->next;
    }
    return currentItem;
}

template<class T>
Link<T> *LinkedListTemplate<T>::erase(std::size_t n)
{
    auto item = advance(n);
    Link<T>* next = nullptr;
    if(item != nullptr) {
        auto prev = item->prev;
        next = item->next;
        if(prev != nullptr)
            prev->next = next;
        if(next != nullptr)
            next->prev = prev;
        item->next = nullptr;
        item->prev = nullptr;
        if(n == 0)
            head_ = next;
        --size_;
    }
    return next;
}

#endif // LINKEDLISTTEMPLATE_H
