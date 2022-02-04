#include <vector>
#include <iostream>
#include "functions.h"

int main() {
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::cout << int_binary_search_iterator(v, 5) - v.begin();
	return 0;
}