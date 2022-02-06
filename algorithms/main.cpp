#include <vector>
#include <iostream>
#include "functions.h"
template<class For>
void print_container(For first, For last) {
	std::cout << "[ ";
	while (first != last)
		std::cout << *first++ << " ";
	std::cout << "]\n";
}

int main() {
	//simple int vector binary search
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::cout << "index of 5 value in vector = " << int_binary_search_iterator(v, 5) - v.begin() << std::endl;
	
	//simple int vector selection sort
	std::vector<int> unsorted_v = { 9, 5, 3, 4, 7, 2, 1, 8, 6};
	int_selection_descending_sort(unsorted_v);
	print_container(unsorted_v.begin(), unsorted_v.end());

	//recursive sum
	std::cout << "vector sum = " << recursive_int_vector_sum(v.begin(), v.end()) << std::endl;

	//recursive size
	std::cout << "vector size = " << items_in_int_vector_range_recursive(v.begin(), v.end()) << std::endl;

	//recursive max
	std::vector<int> unsorted_v2 = { 9, 5, 3, 4, 7, 2, 1, 8, 6};
	std::cout << "max element = " << recursive_int_vector_max_element(unsorted_v2.begin(), unsorted_v2.end()) << std::endl;
	return 0;
}