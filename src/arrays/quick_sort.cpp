#include "quick_sort.hpp"
#include "../common.hpp"

#include <print>
#include <fmt/ranges.h>


void test_quick_sort() {
    std::println("- Array: Quicksort");
    auto array = std::vector<int>{5, 0, 27, 7, 2, 88, 9, 2};
    fmt::println("Before: {}", array);
    quick_sort(array);
    fmt::println("After: {}", array);
}


void quick_sort(std::vector<int>& array, size_t low) {
    quick_sort(array, low, array.size() - 1);
}


void quick_sort(std::vector<int>& array, size_t low, size_t high) {
    if (low >= high) {
        return;
    }

    size_t pivot_index = partition(array, low, high);
    quick_sort(array, low, pivot_index - 1);
    quick_sort(array, pivot_index + 1, high);
}

size_t partition(std::vector<int>& array, size_t low, size_t high) {
    int pivot = array[high];
    size_t i = low - 1;
    for (size_t j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            size_t tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
    }
    i++;
    size_t tmp = array[i];
    array[i] = array[high];
    array[high] = tmp;
    return i;
}