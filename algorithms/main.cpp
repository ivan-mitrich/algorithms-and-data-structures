#include <vector>
#include <iostream>
#include "functions.h"
template<class For>
void print_container(For first, For last) {
	std::cout << "[ ";
	while (first != last)
		std::cout << (*first)++ << " ";
	std::cout << " ]\n";
}

int main() {
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::cout << int_binary_search_iterator(v, 5) - v.begin() << std::endl;
	std::vector<int> unsorted_v = { 9, 5, 3, 4, 7, 2, 1, 8, 6 };
	int_selection_descending_sort(unsorted_v);
	print_container(unsorted_v.begin(), unsorted_v.end());
	return 0;
}