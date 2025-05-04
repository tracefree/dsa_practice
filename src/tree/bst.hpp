#pragma once

#include "binary_tree.hpp"

struct BinarySearchTreeNode {
public:
    int data;
    std::unique_ptr<BinarySearchTreeNode> left;
    std::unique_ptr<BinarySearchTreeNode> right;

public:
    bool is_leaf() const;
    int get_child_count() const;
    bool contains(int value) const;
    void add(int value);
    void add(std::vector<int> values);

    void pre_order_traversal() const;

    BinarySearchTreeNode() {}
    BinarySearchTreeNode(int value);
};

void test_bst();