#include "SinglyLinkedList.h"

UnidirectionalLink* SinglyLinkedList::insert(int n, int v)
{
    auto item = advance(n);
    UnidirectionalLink* newItem = nullptr;
    if (item != nullptr)
    {
        newItem = new UnidirectionalLink(v, item->next);
        item->next = newItem;
    }
    return newItem;
}

UnidirectionalLink* SinglyLinkedList::push_back(int v)
{
    auto newItem = new UnidirectionalLink(v);
    if (head == nullptr)
        head = newItem;
    else {
        UnidirectionalLink* tail = SinglyLinkedList::tail();
        tail->next = newItem;
    }
    ++size_;
    return newItem;
}

UnidirectionalLink* SinglyLinkedList::advance(int n) const
{
    UnidirectionalLink* currentItem = head;
    while (n-- > 0 && currentItem != nullptr)
        currentItem = currentItem->next;
    return currentItem;
}

UnidirectionalLink* SinglyLinkedList::erase(int v)
{
    if (head)
    {
        UnidirectionalLink* currentItem = head;
        while (currentItem->next != nullptr && currentItem->next->value != v)
            currentItem = currentItem->next;
        if (currentItem->next != nullptr)
        {
            auto erasingItem = currentItem->next;
            currentItem->next = erasingItem->next;
            --size_;
        }
    }
    return nullptr;
}

UnidirectionalLink* SinglyLinkedList::find(int v) const
{
    UnidirectionalLink* currentItem = head;
    if (head)
    {
        while (currentItem != nullptr && currentItem->value != v)
            currentItem = currentItem->next;
    }
    return currentItem;
}

UnidirectionalLink* SinglyLinkedList::tail() const
{
    return advance(size_-1);
}
