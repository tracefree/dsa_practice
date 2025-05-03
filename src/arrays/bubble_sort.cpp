#include "bubble_sort.hpp"
#include <print>
#include <fmt/ranges.h>

void bubble_sort(std::vector<int>& array) {
    bool swapped_this_run = false;
    for (size_t run = 0; run < array.size(); run++) {
        swapped_this_run = false;

        for (size_t i = 0; i < array.size() - run - 1; i++) {
            if (array[i] > array[i+1]) {
                int smaller = array[i+1];
                array[i+1] = array[i];
                array[i] = smaller;
                swapped_this_run = true;
            }
        }

        if (!swapped_this_run) {
            return;
        }
    }
}

void test_bubble_sort() {
    std::println("- Array: Bubble Sort");
    auto array = std::vector<int>{5, 0, 27, 7, 2, 88, 9, 2};
    fmt::println("Before: {}", array);
    bubble_sort(array);
    fmt::println("After: {}", array);
}