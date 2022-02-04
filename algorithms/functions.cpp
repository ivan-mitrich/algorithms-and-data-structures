#include "functions.h"

using citer = std::vector<int>::const_iterator;
using vec = std::vector<int>;
citer int_binary_search_iterator(const vec& v, int val)
{
	if (v.empty())
		return v.end();	
	auto low = v.begin();
	auto high = v.end();
	auto middle = low + (high - low) / 2;
	while (low != high) {
		if (*middle == val)
			return middle;
		if (*middle < val)
			low = middle;
		else
			high = middle;
		middle = low + (high - low) / 2;
	}
	return v.end();
}
