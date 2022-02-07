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
	UnidirectionalLink* insert(UnidirectionalLink* link);
	UnidirectionalLink* push_back(int v);
	UnidirectionalLink* advance(int n);
	UnidirectionalLink* erase(int v);
	UnidirectionalLink* find(int v);
	UnidirectionalLink* tail();
	size_t size() { return size_; }
private:
	size_t size_;
	UnidirectionalLink* head;
};

