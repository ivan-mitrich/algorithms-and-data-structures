#include "SinglyLinkedList.h"
#include <iostream>

void printSinglyLinkedList(const SinglyLinkedList& list) {
	std::cout << "[ ";
	for (size_t i = 0; i < list.size(); i++) {
		std::cout << list.advance(i)->value << " ";
	}
	std::cout << "]\n";
	std::cout << list.tail()->value << "\n";
}

int main() {
	SinglyLinkedList list;
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(2);
	list.push_back(3);
	list.push_back(5);
	list.push_back(6);
	list.erase(2);
	list.insert(4, 4);
	printSinglyLinkedList(list);

	return 0;
}