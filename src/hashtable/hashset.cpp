#include "hashset.hpp"
#include <print>
#include <fmt/ranges.h>

HashSet::HashSet() {
    data.resize(10);
}

int HashSet::hash_function(std::string const& value) {
    int character_sum = 0;
    for (const char& character : value) {
        character_sum += character;
    }
    return character_sum % HashSet::NUM_BUCKETS;
}

void HashSet::store(std::string value) {
    int index = HashSet::hash_function(value);
    std::vector<std::string>& bucket = data[index];
    if (std::find(bucket.begin(), bucket.end(), value) == bucket.end()) {
        bucket.emplace_back(value);
    }
}

void HashSet::print_data() const {
    fmt::println("Data: {}", data);
}

bool HashSet::contains(std::string const& value) const {
    int index = HashSet::hash_function(value);
    const std::vector<std::string>& bucket = data[index];
    return std::find(bucket.begin(), bucket.end(), value) != bucket.end();
}

void test_hashset() {
    std::println("- Hash Table: HashSet");
    std::println("'Hello World' has hash code: {}", HashSet::hash_function("Hello World"));
    HashSet table;
    table.store("Hello World");
    table.store("John");
    table.store("Monica");
    table.store("Manfred");
    table.store("Rie");
    table.print_data();

    std::println("Set contains 'Rie': {}", table.contains("Rie"));
    std::println("Set contains 'John': {}", table.contains("John"));
    std::println("Set contains 'Monica': {}", table.contains("Monica"));
}