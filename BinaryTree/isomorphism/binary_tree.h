#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <algorithm>
#include <vector>
#include "queue.h"

using namespace std;

template <typename ElementType>
class BinaryTreeNode {
 public:
  ElementType data_;
  BinaryTreeNode* left_;
  BinaryTreeNode* right_;
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

template<typename ElementType>
class BinaryTree {
 public:
  BinaryTreeNode<ElementType>* root_;
 public:
  BinaryTree() {
    root_ = nullptr;
  }
  BinaryTree(ElementType data) {
    root_ = new BinaryTreeNode<ElementType>(data);
  }
  BinaryTree(BinaryTreeNode<ElementType>* root) {
    root_ = root;
  }
 public:
  void LevelOrderTraversal(vector<ElementType>& result_vec);
};

template <typename ElementType>
void BinaryTree<ElementType>::LevelOrderTraversal(vector<ElementType>& result_vec) {
  Queue<BinaryTreeNode<ElementType>*> queue;
  queue.In(root_);
  BinaryTreeNode<ElementType>* ptr = nullptr;
  while(!(queue.IsEmpty())) {
    ptr = queue.Out();
    result_vec.push_back(ptr->data_);

    if(ptr->left_ != nullptr)
      queue.In(ptr->left_);

    if(ptr->right_ != nullptr)
      queue.In(ptr->right_);
  }
}


/* ------------用数组描述二叉树信息------------- */
/* ------------------示例-------------------- */
/* root:  | G | B | F | A | H | C | D | E |  */
/* left:  | - | E | - | C | - | G | - | F |  */
/* right: | H | D | - | B | - | - | - | - |  */
/* ----------------------------------------- */
class ArrayNode {
 public:
  char root_node_;
  char left_child_node_;
  char right_child_node_;
 public:
  ArrayNode() {
    root_node_ = '-';
    left_child_node_ = '-';
    right_child_node_ = '-';
  }
  ArrayNode(char root, char left_child, char right_child) {
    root_node_ = root;
    left_child_node_ = left_child;
    right_child_node_ = right_child;
  }
};


// 已知二叉树根节点，递归实现根据输入的二叉树数组描述重构二叉树
void RebuildBinaryTree(ArrayNode* array, int array_size, char root_node,
                       BinaryTree<char>* result_tree) {
  int root_node_index = -1;
  // 先找到根节点在数组中的位置
  for(int i = 0; i < array_size; i++) {
    if((array+i)->root_node_ == root_node)
      root_node_index = i;
  }

  if( ((array+root_node_index)->left_child_node_ == '-')
      && ((array+root_node_index)->right_child_node_ == '-') )     // 叶结点
    return;

  if( (array+root_node_index)->left_child_node_ != '-' ) {
    BinaryTree<char>* left_child_tree =
      new BinaryTree<char>((array+root_node_index)->left_child_node_);
    RebuildBinaryTree(array, array_size,
      (array+root_node_index)->left_child_node_, left_child_tree);
    (result_tree->root_->left_) = left_child_tree->root_;
  }

  if( (array+root_node_index)->right_child_node_ != '-') {
    BinaryTree<char>* right_child_tree =
      new BinaryTree<char>((array+root_node_index)->right_child_node_);
    RebuildBinaryTree(array, array_size,
      (array+root_node_index)->right_child_node_, right_child_tree);
    (result_tree->root_->right_) = right_child_tree->root_;
  }
}

// 根据输入的数组描述二叉树信息重构二叉树
BinaryTree<char>* RebuildBinaryTree(ArrayNode* array, int array_size) {
  // 根据输入数组描述信息寻找二叉树的根节点
  vector<char> node_set;    // 二叉树包含的所有节点
  vector<char> child_node_set;  // 二叉树非根节点的集合
  for( int i = 0; i < array_size; i++ ) {
    node_set.push_back((array+i)->root_node_);
    if((array+i)->left_child_node_ != '-')
      child_node_set.push_back((array+i)->left_child_node_);
    if((array+i)->right_child_node_ != '-')
      child_node_set.push_back((array+i)->right_child_node_);
  }
  sort(node_set.begin(), node_set.end());   // 所有结点从小到大排列
  sort(child_node_set.begin(), child_node_set.end());  // 非根结点从小到大排列
  char root_node = node_set[array_size-1];
  for(int i = 0; i < array_size - 1; i++) {
    if(node_set[i] != child_node_set[i]) {
      root_node = node_set[i];
      break;
    }
  }

  // 构造二叉树
  BinaryTree<char>* result_tree = new BinaryTree<char>(root_node);
  RebuildBinaryTree(array, array_size, root_node, result_tree);
  return result_tree;
}

bool IsIsomorphic(BinaryTree<char>* tree1, BinaryTree<char>* tree2) {
  // 两个树都为空，则同构
  if(((tree1->root_) == nullptr) && ((tree2->root_) == nullptr))
    return true;

  // 一个树为空，另一个不为空，则不同构
  if((((tree1->root_) == nullptr) && ((tree2->root_ != nullptr))) ||
     (((tree1->root_) != nullptr) && ((tree2->root_ == nullptr))))
    return false;

  if(((tree1->root_) != nullptr) && ((tree2->root_) != nullptr)) {
    // 根节点不同则不同构
    if((tree1->root_->data_) != (tree2->root_->data_))
      return false;

    vector<char> result_vec1, result_vec2;
    tree1->LevelOrderTraversal(result_vec1);
    tree2->LevelOrderTraversal(result_vec2);
    auto tree1_size = result_vec1.size();
    auto tree2_size = result_vec2.size();
    // 两颗树所含节点数不同，则不同构
    if(tree1_size != tree2_size)
      return false;

    // 两颗树都只有一个结点（根节点），则如果根节点相同则同构
    if(tree1_size == 1) {
      if((tree1->root_->data_) == (tree2->root_->data_))
        return true;
      else
        return false;
    }

    // 有一侧子树为空的情况
    // A左空且B左空，比较A右子树和B右子树是否同构
    if((tree1->root_->left_ == nullptr) && (tree2->root_->left_ == nullptr)) {
      BinaryTree<char>* tree1_right_subtree =
        new BinaryTree<char>(tree1->root_->right_);
      BinaryTree<char>* tree2_right_subtree =
        new BinaryTree<char>(tree2->root_->right_);
      return IsIsomorphic(tree1_right_subtree, tree2_right_subtree);
    }
    // A左空且B右空，比较A右子树和B左子树是否同构
    if((tree1->root_->left_ == nullptr) && (tree2->root_->right_ == nullptr)) {
      BinaryTree<char>* tree1_right_subtree =
        new BinaryTree<char>(tree1->root_->right_);
      BinaryTree<char>* tree2_left_subtree =
        new BinaryTree<char>(tree2->root_->left_);
      return IsIsomorphic(tree1_right_subtree, tree2_left_subtree);
    }
    // A右空且B左空,比较A左子树和B右子树是否同构
    if((tree1->root_->right_ == nullptr) && (tree2->root_->left_ == nullptr)) {
      BinaryTree<char>* tree1_left_subtree =
        new BinaryTree<char>(tree1->root_->left_);
      BinaryTree<char>* tree2_right_subtree =
        new BinaryTree<char>(tree2->root_->right_);
      return IsIsomorphic(tree1_left_subtree, tree2_right_subtree);
    }
    // A右空且B右空，比较A左子树和B左子树是否同构
    if((tree1->root_->right_ == nullptr) && (tree2->root_->right_ == nullptr)) {
      BinaryTree<char>* tree1_left_subtree =
        new BinaryTree<char>(tree1->root_->left_);
      BinaryTree<char>* tree2_left_subtree =
        new BinaryTree<char>(tree2->root_->left_);
      return IsIsomorphic(tree1_left_subtree, tree2_left_subtree);
    }

    if(((tree1->root_->left_->data_) == (tree2->root_->left_->data_)) &&
       ((tree1->root_->right_->data_) == (tree2->root_->right_->data_))) {
      BinaryTree<char>* tree1_left_subtree =
        new BinaryTree<char>(tree1->root_->left_);
      BinaryTree<char>* tree1_right_subtree =
        new BinaryTree<char>(tree1->root_->right_);
      BinaryTree<char>* tree2_left_subtree =
        new BinaryTree<char>(tree2->root_->left_);
      BinaryTree<char>* tree2_right_subtree =
        new BinaryTree<char>(tree2->root_->right_);

      // BinaryTree<char> *tree1_right_subtree;
      // (tree1_left_subtree->root_) = tree1->root_->left_;
      // (tree1_right_subtree->root_) = tree1->root_->right_;
      // BinaryTree<char> *tree2_left_subtree, *tree2_right_subtree;
      // (tree2_left_subtree->root_) = tree2->root_->left_;
      // (tree2_right_subtree->root_) = tree2->root_->right_;
      // 比较两个树的左子树是否同构，右子树是否同构
      bool is_left_subtree_isomorphic = IsIsomorphic(tree1_left_subtree,
                                                     tree2_left_subtree);
      bool is_right_subtree_isomorphic = IsIsomorphic(tree1_right_subtree,
                                                      tree2_right_subtree);
      return is_left_subtree_isomorphic && is_right_subtree_isomorphic;
    }
    else if (((tree1->root_->left_->data_) == (tree2->root_->right_->data_)) &&
             ((tree1->root_->right_->data_) == (tree2->root_->left_->data_))) {
      BinaryTree<char>* tree1_left_subtree =
        new BinaryTree<char>(tree1->root_->left_);
      BinaryTree<char>* tree1_right_subtree =
        new BinaryTree<char>(tree1->root_->right_);
      BinaryTree<char>* tree2_left_subtree =
        new BinaryTree<char>(tree2->root_->left_);
      BinaryTree<char>* tree2_right_subtree =
        new BinaryTree<char>(tree2->root_->right_);

      // BinaryTree<char> *tree1_left_subtree, *tree1_right_subtree;
      // (tree1_left_subtree->root_) = tree1->root_->left_;
      // (tree1_right_subtree->root_) = tree1->root_->right_;
      // BinaryTree<char> *tree2_left_subtree, *tree2_right_subtree;
      // (tree2_left_subtree->root_) = tree2->root_->left_;
      // (tree2_right_subtree->root_) = tree2->root_->right_;

      // 比较tree1的左子树和tree2的右子树是否同构
      bool is_tree1_left_subtree_isomorphic_tree2_right_subtree = IsIsomorphic(
        tree1_left_subtree, tree2_right_subtree
      );
      // 比较tree1的右子树和tree2的左子树是否同构
      bool is_tree1_right_subtree_isomorphic_tree2_left_subtree = IsIsomorphic(
        tree1_right_subtree, tree2_left_subtree
      );
      return is_tree1_left_subtree_isomorphic_tree2_right_subtree &&
             is_tree1_right_subtree_isomorphic_tree2_left_subtree;
    }
    else
      return false;
  }

  return false;
}

#endif // __BINARY_TREE_H