#include "SinglyLinkedList.h"

UnidirectionalLink* SinglyLinkedList::insert(UnidirectionalLink* link)
{
    return nullptr;
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

UnidirectionalLink* SinglyLinkedList::advance(int n)
{
    UnidirectionalLink* currentItem = head;
    while (n-- > 0)
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
        auto erasingItem = currentItem->next;
        currentItem->next = erasingItem->next;
        delete erasingItem;
    }
    return nullptr;
}

UnidirectionalLink* SinglyLinkedList::find(int v)
{
    UnidirectionalLink* currentItem = head;
    if (head)
    {
        while (currentItem != nullptr && currentItem->value != v)
            currentItem = currentItem->next;
    }
    return currentItem;
}

UnidirectionalLink* SinglyLinkedList::tail()
{
    return advance(size_);
}
