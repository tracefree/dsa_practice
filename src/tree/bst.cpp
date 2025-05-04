#include "bst.hpp"

#include <print>


BinarySearchTreeNode::BinarySearchTreeNode(int value) {
    data = value;
}

void BinarySearchTreeNode::add(int value) {
    if (value == data) return;
    if (value < data) {
        if (left == nullptr) {
            left = std::make_unique<BinarySearchTreeNode>(value);
        } else {
            left->add(value);
        }
    } else {
        if (right == nullptr) {
            right = std::make_unique<BinarySearchTreeNode>(value);
        } else {
            right->add(value);
        }
    }
}

void BinarySearchTreeNode::pre_order_traversal() const {
    std::print("{} ", data);
    if (left != nullptr) {
        left->pre_order_traversal();
    }
    if (right != nullptr) {
        right->pre_order_traversal();
    }
}

int BinarySearchTreeNode::get_child_count() const {
    int child_count = 0;
    if (left != nullptr) {
        child_count++;
    }
    if (right != nullptr) {
        child_count++;
    }
    return child_count;
}

bool BinarySearchTreeNode::is_leaf() const {
    return get_child_count() == 0;
}

void BinarySearchTreeNode::add(std::vector<int> values) {
    for (auto value : values) {
        add(value);
    }
}

bool BinarySearchTreeNode::contains(int value) const {
    if (data == value) return true;
    if (value < data) {
        if (left == nullptr) {
            return false;
        } else {
            return left->contains(value);
        }
    } else {
        if (right == nullptr) {
            return false;
        } else {
            return right->contains(value);
        }
    }
}

void test_bst() {
    std::println("- Tree: Binary Search Tree");
    BinarySearchTreeNode bst(13);
    bst.add({7, 15, 3, 8, 14, 19, 18});

    std::print("Pre-order traversal: ");
    bst.pre_order_traversal();
    std::print("\n");

    std::println("BST contains '10': {}", bst.contains(10));
    std::println("BST contains '19': {}", bst.contains(19));
}