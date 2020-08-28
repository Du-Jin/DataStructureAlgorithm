#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

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
};

template<typename ElementType>
int CalHeight(BinaryTreeNode<ElementType>* root_) {
  int l_height = 1;
  if(root_->left_ != nullptr) {
    l_height = CalHeight(root_->left_) + 1;
  }

  int r_height = 1;
  if(root_->right_ != nullptr) {
    r_height = CalHeight(root_->right_) + 1;
  }

  return ((l_height > r_height) ? l_height : r_height);
}

#endif // __BINARY_TREE