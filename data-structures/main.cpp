#include "SinglyLinkedList.h"
#include "linkedlisttemplate.h"
#include <iostream>

void printSinglyLinkedList(const SinglyLinkedList& list) {
	std::cout << "[ ";
	for (size_t i = 0; i < list.size(); i++) {
		std::cout << list.advance(i)->value << " ";
	}
	std::cout << "]\n";
	std::cout << list.tail()->value << "\n";
}

int listTemplateTest()
{
    LinkedListTemplate<int> list;
    list.pushBack(1);
    list.pushFront(0);
    list.add(1,3);
    list.insert(2,2);
    list.pushBack(3);
    list.erase(list.size()-1);
    list.erase(0);
    list.insert(0, 0);
    list.erase(-5);
    std::cout << "[ ";
    auto current = list.head();
    while(current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "]\n";

    LinkedListTemplate<Point> pointlist;
    pointlist.pushBack(Point(1,1));
    pointlist.pushFront(Point(0,0));
    pointlist.add(1, Point(3,3));
    pointlist.insert(2, Point(2,2));
    pointlist.pushBack(Point(3,3));
    pointlist.erase(list.size()-1);
    pointlist.erase(0);
    pointlist.insert(0, Point(0,0));
    pointlist.erase(-5);
    std::cout << "[ ";
    auto current2 = pointlist.head();
    while(current2 != nullptr)
    {
        std::cout << current2->value << " ";
        current2 = current2->next;
    }
    std::cout << "]\n";

    return 0;
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
	listTemplateTest();
	return 0;
}