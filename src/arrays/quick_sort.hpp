#pragma once

#include <vector>

void test_quick_sort();
void quick_sort(std::vector<int>& array, size_t low = 0);
void quick_sort(std::vector<int>& array, size_t low, size_t high);
size_t partition(std::vector<int>& array, size_t low, size_t high);