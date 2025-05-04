#include "common.hpp"
#include <print>

std::vector<size_t> create_range(size_t start, size_t end) {
    auto range = std::vector<size_t>(end - start + 1);
    for (size_t i = 0; i < range.size(); i++) {
        range[i] = start + i;
    }
    return range;
}