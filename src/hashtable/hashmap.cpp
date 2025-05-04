#include "hashmap.hpp"

#include <print>
#include <fmt/ranges.h>


template<typename V>
int HashMap<V>::hash_function(std::string const& value) {
    int character_sum = 0;
    for (const char& character : value) {
        character_sum += character;
    }
    return character_sum % HashMap::NUM_BUCKETS;
}

template<typename V>
bool HashMap<V>::contains(std::string const& key) const {
    int index = HashMap<V>::hash_function(key);
    std::vector<std::tuple<std::string, V>> const & bucket = data[index];
    for (const auto& entry : bucket) {
        if (std::get<0>(entry) == key) {
            return true;
        }
    }
    return false;
}

template<typename V>
void HashMap<V>::store(std::string const& key, V value) {
    int index = HashMap<V>::hash_function(key);
    std::vector<std::tuple<std::string, V>>& bucket = data[index];
    for (auto& entry : bucket) {
        if (std::get<0>(entry) == key) {
            return;
        }
    }
    std::tuple<std::string, V> entry = {key, value};
    bucket.emplace_back(entry);
}

template<typename V>
V HashMap<V>::get(std::string const& key) const {
    int index = HashMap<V>::hash_function(key);
    std::vector<std::tuple<std::string, V>> const& bucket = data[index];
    for (const auto& entry : bucket) {
        if (std::get<0>(entry) == key) {
            return std::get<1>(entry);
        }
    }
    return V();
}

template<typename V>
void HashMap<V>::print_data() const {
    fmt::println("Data: {}", data);
}

void test_hashmap() {
    std::println("- Hash Table: Hash Map");
    HashMap<int> hashmap;
    hashmap.store("Rie", 42);
    hashmap.print_data();
    std::println("Contains 'Rie': {}", hashmap.contains("Rie"));
    std::println("Contains 'Monica': {}", hashmap.contains("Monica"));
    std::println("Value for 'Rie': {}", hashmap.get("Rie"));

    HashMap<std::string> last_names;
    last_names.store("John", "von Neumann");
    last_names.store("Emmy", "Noether");
    std::println("Last name for 'Emmy': {}", last_names.get("Emmy"));
}

