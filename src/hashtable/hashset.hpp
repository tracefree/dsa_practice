#pragma once

#include <vector>
#include <string>

struct HashSet {
public:
    static const int NUM_BUCKETS = 10;

protected:
    std::vector<std::vector<std::string>> data {NUM_BUCKETS};

public:
    static int hash_function(std::string const& value);
    void store(std::string value);
    void print_data() const;
    bool contains(std::string const& value) const;

    HashSet();
    ~HashSet() {}
};

void test_hashset();