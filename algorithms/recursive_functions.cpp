#include "functions.h"
#include <algorithm>
#include <random>

using iter = std::vector<int>::iterator;
using citer = std::vector<int>::const_iterator;
using vec = std::vector<int>;
using sz = std::vector<int>::size_type;

int recursive_int_vector_sum(citer first, citer last) {
	if (first == last)
		return 0;
	return ((*first++) + recursive_int_vector_sum(first, last));
}

sz items_in_int_vector_range_recursive(citer first, citer last) {
	if (first == last)
		return 0;
	return 1 + items_in_int_vector_range_recursive(++first, last);
}

int recursive_int_vector_max_element(citer first, citer last) {
	if (first + 1 == last)
		return *first;
	auto v1 = *first;
	return std::max(v1, recursive_int_vector_max_element(++first, last));
}

sz random_index_in_range(sz start, sz finish) {
	const int range_from = start;
	const int range_to = finish;
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<sz>  distr(range_from, range_to);
	return distr(generator);
}

vec int_vector_quicksort(iter first, iter last) {
	vec v(last - first);
	if (first + 1 == last) {
		v.push_back(*first);
		return v;
	}
	iter middle = first + random_index_in_range(0, last - first);
	auto std::copy_if(first, last, v.begin(), [&](int) {})
}