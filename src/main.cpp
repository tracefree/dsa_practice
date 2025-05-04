#include "fibonacci.hpp"
#include "arrays/bubble_sort.hpp"
#include "arrays/quick_sort.hpp"
#include "hashtable/hashset.hpp"
#include "hashtable/hashmap.hpp"
#include "tree/binary_tree.hpp"
#include "tree/bst.hpp"

#include <print>


int main() {
    std::println("=== Data structures and algorithms ===");
    test_fibonacci();
    test_bubble_sort();
    test_quick_sort();
    test_hashset();
    test_hashmap();
    test_binary_tree();
    test_bst();
    return 0;
}