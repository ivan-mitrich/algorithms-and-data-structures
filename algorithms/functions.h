#pragma once
#include <vector>

std::vector<int>::const_iterator int_binary_search_iterator(const std::vector<int>&, int);
void int_selection_descending_sort(std::vector<int>&);

//recursive algorithms
int recursive_int_vector_sum(std::vector<int>::const_iterator, std::vector<int>::const_iterator);
std::vector<int>::size_type items_in_int_vector_range_recursive(std::vector<int>::const_iterator, std::vector<int>::const_iterator);
int recursive_int_vector_max_element(std::vector<int>::const_iterator, std::vector<int>::const_iterator);
