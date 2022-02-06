#include "functions.h"

using citer = std::vector<int>::const_iterator;
using vec = std::vector<int>;
using sz = std::vector<int>::size_type;

int recursive_int_vector_sum(citer first, citer last) {
	if (first == last)
		return 0;
	return ((*first++) + recursive_int_vector_sum(first, last));
}