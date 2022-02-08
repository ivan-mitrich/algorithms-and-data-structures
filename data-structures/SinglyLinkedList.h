#pragma once

struct UnidirectionalLink
{
	int value;
	UnidirectionalLink* next;
	UnidirectionalLink(int v = 0, UnidirectionalLink* p = nullptr) : value(v), next(p) {}
};

class SinglyLinkedList
{
public:
	SinglyLinkedList() : size_(0), head(nullptr) { }
	UnidirectionalLink* insert(int n, int v);
	UnidirectionalLink* push_back(int v);
	UnidirectionalLink* advance(int n) const;
	UnidirectionalLink* erase(int v);
	UnidirectionalLink* find(int v) const;
	UnidirectionalLink* tail() const;
	size_t size() const { return size_; }
private:
	size_t size_;
	UnidirectionalLink* head;
};

