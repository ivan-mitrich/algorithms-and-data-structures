#include "functions.h"
#include <utility>

using citer = std::vector<int>::const_iterator;
using vec = std::vector<int>;
using sz = std::vector<int>::size_type;

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

void int_selection_descending_sort(vec& v) {
	sz min_index = 0;
	for (sz i = 0; i < v.size(); ++i) {
		min_index = i;
		auto elem = v[i];
		for (sz j = i+1; j < v.size(); ++j) {
			if (elem < v[j])
			{
				min_index = j;
				elem = v[j];
			}
		}
		std::swap(v[i], v[min_index]);
	}
}

