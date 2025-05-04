#pragma once
#include <vector>
#include <memory>

template <typename T>
struct BinaryTreeNode {
public:
    T data;
    std::unique_ptr<BinaryTreeNode<T>> left;
    std::unique_ptr<BinaryTreeNode<T>> right;

    void pre_order_traversal();
    void in_order_traversal();
    void post_order_traversal();

    BinaryTreeNode() {}
    BinaryTreeNode(T value);
    ~BinaryTreeNode();
};

void test_binary_tree();