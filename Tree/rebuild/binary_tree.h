#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <vector>
#include "stack.h"

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


// 功能：利用先序遍历结果和中序遍历结果构造二叉树结构
template <typename ElementType>
void RebuildTree( const vector<ElementType>& preorder_result_vec,
                  const vector<ElementType>& inorder_result_vec,
                  BinaryTree<ElementType>* result_tree) {
  if(preorder_result_vec.empty())
    return;

  BinaryTreeNode<ElementType>* root = new BinaryTreeNode<ElementType>(preorder_result_vec[0]);
  (result_tree->root_) = root;

  // 得到左子树和右子树的先序结果和后序结果
  vector<ElementType> left_subtree_preorder;
  vector<ElementType> right_subtree_preorder;
  vector<ElementType> left_subtree_inorder;
  vector<ElementType> right_subtree_inorder;
  for(auto it_begin = inorder_result_vec.begin(); it_begin < inorder_result_vec.end(); it_begin++) {
    if(*it_begin != preorder_result_vec[0]) {
      left_subtree_inorder.push_back(*it_begin);
    }
    else {
      break;
    }
  }
  for(typename vector<ElementType>::size_type i = 1; i <= left_subtree_inorder.size();i++) {
    left_subtree_preorder.push_back(preorder_result_vec[i]);
  }
  for(typename vector<ElementType>::size_type i = left_subtree_preorder.size()+1; i < preorder_result_vec.size(); i++) {
    right_subtree_preorder.push_back(preorder_result_vec[i]);
  }
  for(typename vector<ElementType>::size_type i = left_subtree_inorder.size() + 1; i < inorder_result_vec.size(); i++) {
    right_subtree_inorder.push_back(inorder_result_vec[i]);
  }

  // 重构二叉树
  if(left_subtree_preorder.size()) {
    BinaryTree<ElementType>* left_subtree = new BinaryTree<ElementType>();
    RebuildTree(left_subtree_preorder, left_subtree_inorder, left_subtree);
    (result_tree->root_->left_) = left_subtree->root_;
  }
  if(right_subtree_preorder.size()) {
    BinaryTree<ElementType>* right_subtree = new BinaryTree<ElementType>();
    RebuildTree(right_subtree_preorder, right_subtree_inorder, right_subtree);
    (result_tree->root_->right_) = right_subtree->root_;
  }
}

#endif // __BINARY_TREE