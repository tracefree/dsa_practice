#pragma once
#include <vector>
#include <string>

template <typename V>
struct HashMap {
public:
    static const int NUM_BUCKETS = 10;
 
protected:
    std::vector<std::vector<std::tuple<std::string, V>>> data { NUM_BUCKETS };

public:
    static int hash_function(std::string const& value);
    bool contains(std::string const& key) const;
    void store(std::string const& key, V value);
    V get(std::string const&  key) const;
    void print_data() const;
};

void test_hashmap();