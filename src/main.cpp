#include "fibonacci.hpp"
#include "arrays/bubble_sort.hpp"
#include "arrays/quick_sort.hpp"

#include <print>


int main() {
    std::println("=== Data structures and algorithms ===");
    test_fibonacci();
    test_bubble_sort();
    test_quick_sort();
    return 0;
}