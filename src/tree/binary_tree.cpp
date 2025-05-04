#include "binary_tree.hpp"

#include <print>


template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T value) {
    data = value;
}

template <typename T>
BinaryTreeNode<T>::~BinaryTreeNode() {
    // std::println("Deleting node: {}", data);
}

template <typename T>
void BinaryTreeNode<T>::pre_order_traversal() {
    std::print("{} ", data);
    if (left != nullptr) {
        left->pre_order_traversal();
    }
    if (right != nullptr) {
        right->pre_order_traversal();
    }
}

template <typename T>
void BinaryTreeNode<T>::in_order_traversal() {
    if (left != nullptr) {
        left->in_order_traversal();
    }
    std::print("{} ", data);
    if (right != nullptr) {
        right->in_order_traversal();
    }
}

template <typename T>
void BinaryTreeNode<T>::post_order_traversal() {
    if (left != nullptr) {
        left->post_order_traversal();
    }
    if (right != nullptr) {
        right->post_order_traversal();
    }
    std::print("{} ", data);
}

void test_binary_tree() {
    std::println("- Tree: Binary tree");
    BinaryTreeNode<char> tree('R');
    
    tree.left = std::make_unique<BinaryTreeNode<char>>('A');
    tree.right = std::make_unique<BinaryTreeNode<char>>('B');

    tree.left->left = std::make_unique<BinaryTreeNode<char>>('C');
    tree.left->right = std::make_unique<BinaryTreeNode<char>>('D');

    tree.right->left = std::make_unique<BinaryTreeNode<char>>('E');
    tree.right->right = std::make_unique<BinaryTreeNode<char>>('F');

    tree.right->right->left = std::make_unique<BinaryTreeNode<char>>('G');

    std::println("Root->R->L: {}", tree.right->left->data);

    // Used for ceating a copy of a tree
    std::print("Pre-order traversal: ");
    tree.pre_order_traversal();
    std::print("\n");

    // Used for return values in ascending order in binary search trees
    std::print("In-order traversal: ");
    tree.in_order_traversal();
    std::print("\n");

    // Used for deleting a tree
    std::print("Post-order traversal: ");
    tree.post_order_traversal();
    std::print("\n");
}