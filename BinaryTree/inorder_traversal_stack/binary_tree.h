#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include "stack.h"
#include <vector>
#include <memory>

using namespace std;

template<typename ElementType>
class BinaryTreeNode {
public:
  ElementType data_;
  BinaryTreeNode<ElementType>* left_;
  BinaryTreeNode<ElementType>* right_;
public:
  BinaryTreeNode() {
    left_ = nullptr;
    right_ = nullptr;
  }
  BinaryTreeNode(ElementType data) {
    data_ = data;
    left_ = nullptr;
    right_ = nullptr;
  }
};

enum InsertPosition {
  LEFT, RIGHT
};

template<typename ElementType>
class BinaryTree {
public:
  BinaryTreeNode<ElementType>* root_;
public:
  BinaryTree() {
    root_ = nullptr;
  }
  BinaryTree(BinaryTreeNode<ElementType>* binary_tree_node_addr) {
    root_ = binary_tree_node_addr;
  }
public:
  bool IsEmpty() { return root_ == nullptr; }
  void Insert(BinaryTree<ElementType>* subtree,
              InsertPosition insert_position) {
    (insert_position == LEFT) ? (root_->left_ = subtree->root_) :
                                (root_->right_ = subtree->root_);
  }
  void InorderTraversalStack(vector<ElementType>& result_vec);
};

template<typename ElementType>
void BinaryTree<ElementType>::InorderTraversalStack(
                            vector<ElementType>& result_vec) {
  Stack< BinaryTreeNode<ElementType>* > stack;
  BinaryTreeNode<ElementType>* ptr = root_;

  while(ptr != nullptr || !(stack.IsEmpty())) {
    while(ptr) {
      stack.Push(ptr);
      ptr = ptr->left_;
    }
    if(!(stack.IsEmpty())) {
      ptr = stack.Pop();
      result_vec.push_back(ptr->data_);
      ptr = ptr->right_;
    }
  }
}

#endif // __BINARY_TREE