#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <vector>
using namespace std;

template <typename ElementType>
class BinarySearchTreeNode {
 public:
  ElementType data_;
  BinarySearchTreeNode<ElementType>* parent_;
  BinarySearchTreeNode<ElementType>* left_child_;
  BinarySearchTreeNode<ElementType>* right_child_;
 public:
  BinarySearchTreeNode() {
    parent_ = nullptr;
    left_child_ = nullptr;
    right_child_ = nullptr;
  }
  BinarySearchTreeNode(ElementType data) {
    data_ = data;
    parent_ = nullptr;
    left_child_ = nullptr;
    right_child_ = nullptr;
  }
};

template<typename ElementType>
class BinarySearchTree {
public:
  BinarySearchTreeNode<ElementType>* root_;

public:
  BinarySearchTree() {
    root_ = nullptr;
  }
  BinarySearchTree(BinarySearchTreeNode<ElementType>* root) {
    root_ = root;
  }
  BinarySearchTree(ElementType data) {
    root_ = new BinarySearchTreeNode<ElementType>(data);
  }
};

// 给定序列（元素类型相同，且彼此不相等），构造对应的二叉搜索树
// 返回构造成功与否
template <typename ElementType>
bool Build(
    const vector<ElementType>& sequence,
    BinarySearchTree<ElementType>* result_tree) {
  if(sequence.empty())
    return false;
  // 插入第一个数作为根节点
  (result_tree->root_) = new BinarySearchTreeNode<ElementType>(sequence[0]);
  // 插入剩余的数在树合适的位置
  for(typename vector<ElementType>::size_type i = 1; i < sequence.size(); i++) {
    BinarySearchTreeNode<ElementType>* node =
        new BinarySearchTreeNode<ElementType>(sequence[i]);  // 要插入的结点
    BinarySearchTreeNode<ElementType>* ptr = result_tree->root_;
    while(1) {
      if((node->data_) < (ptr->data_)) {
        if((ptr->left_child_) == nullptr) {
          (ptr->left_child_) = node;
          (node->parent_) = ptr;
          break;
        }
        else
          ptr = ptr->left_child_;
      }
      else if((node->data_) > (ptr->data_)) {
        if((ptr->right_child_) == nullptr) {
          (ptr->right_child_) = node;
          (node->parent_) = ptr;
          break;
        }
        else
          ptr = ptr->right_child_;
      }
      else
        return false;
    }
  }
  return true;
}

// 二叉搜索树的查找
// 给定二叉搜索树和要搜索的元素，返回对应结点的地址
// 参数1：给定二叉搜索树的根节点的地址
// 参数2：要搜索的结点元素值
// 使用递归的方法实现
// template <typename ElementType>
// BinarySearchTreeNode<ElementType>* Search(
//     BinarySearchTreeNode<ElementType>* root,
//     ElementType data) {
//   if(root == nullptr)
//     return nullptr;

//   if(data == root->data_)
//     return root;
//   else if(data < root->data_) {    // 往左子树找
//     if((root->left_child_) == nullptr)  // 不存在对应结点
//       return nullptr;
//     else {
//       return Search(root->left_child_, data);
//     }
//   }
//   else {                           // 往右子树找
//     if((root->right_child_) == nullptr) // 不存在对应结点
//       return nullptr;
//     else {
//       return Search(root->right_child_, data);
//     }
//   }
// }

// 二叉搜索树的查找
// 给定二叉搜索树和要搜索的元素，返回对应结点的地址
// 参数1：给定二叉搜索树的根节点的地址
// 参数2：要搜索的结点元素值
// 使用非递归（循环）的方法实现
template <typename ElementType>
BinarySearchTreeNode<ElementType>* Search(
    BinarySearchTreeNode<ElementType>* root,
    ElementType data ) {
  BinarySearchTreeNode<ElementType>* ptr = root;
  while(1) {
    if(ptr == nullptr)
      return nullptr;

    if(data == ptr->data_) {
      return ptr;
    }
    else if(data < (ptr->data_)) {
      if((ptr->left_child_) == nullptr)
        return nullptr;
      else
        ptr = ptr->left_child_;
    }
    else {
      if((ptr->right_child_) == nullptr)
        return nullptr;
      else
        ptr = ptr->right_child_;
    }
  }
}

// 二叉搜索树的插入操作
// 参数1：二叉搜索树根节点的地址
// 参数2：要插入结点的引用
template <typename ElementType>
bool Insert(BinarySearchTreeNode<ElementType>* root,
            BinarySearchTreeNode<ElementType>& node) {
  if(root == nullptr)
    return false;

  BinarySearchTreeNode<ElementType>* ptr = root;
  while(1) {
    if((node.data_) == (ptr->data_))
      return false;
    else if((node.data_) < (ptr->data_)) {
      if((ptr->left_child_) == nullptr) {
        (ptr->left_child_) = &node;
        (node.parent_) = ptr;
        return true;
      }
      else
        ptr = ptr->left_child_;
    }
    else {
      if((ptr->right_child_) == nullptr) {
        (ptr->right_child_) = &node;
        (node.parent_) = ptr;
        return true;
      }
      else
        ptr = ptr->right_child_;
    }
  }
}

// 二叉搜索树的删除
// 参数1：二叉搜索树的根节点地址
// 参数2：要删除的结点元素值
template <typename ElementType>
bool Delete(BinarySearchTree<ElementType>* tree,
           ElementType data) {
  if(tree == nullptr)
    return false;

  if((tree->root_) == nullptr)
    return false;

  if(data < (tree->root_->data_)) {    // 左子树递归执行删除操作
    BinarySearchTree<ElementType>* left_subtree = new
        BinarySearchTree<ElementType>(tree->root_->left_child_);
    return Delete(left_subtree, data);
  }
  else if (data > (tree->root_->data_)) {    // 右子树递归执行删除操作
    BinarySearchTree<ElementType>* right_subtree = new
        BinarySearchTree<ElementType>(tree->root_->right_child_);
    return Delete(right_subtree, data);
  }
  else {
    if((tree->root_->left_child_) &&
       (tree->root_->right_child_)) {    // 要删除结点有左右两个子节点
      // 在要删除节点左子树中寻找最大结点来填充要删除的结点
      BinarySearchTreeNode<ElementType>* ptr = tree->root_->left_child_;
      while(ptr->right_child_) {
        ptr = ptr->right_child_;
      }
      (tree->root_->data_) = ptr->data_;
      // 在左子树中删除最大结点
      BinarySearchTree<ElementType>* left_subtree = new
          BinarySearchTree<ElementType>(tree->root_->left_child_);
      return Delete(left_subtree, ptr->data_);
    }
    else {  // 要删除结点仅有一个子节点或无子节点
      if(tree->root_->left_child_) {  // 左子节点存在
        auto parent = tree->root_->parent_;
        auto child = tree->root_->left_child_;
        if((parent->left_child_) == tree->root_)
          (parent->left_child_) = child;
        else
          (parent->right_child_) = child;
        (child->parent_) = parent;
        (tree->root_) = child;
      }
      else if(tree->root_->right_child_) { // 右子节点存在
        auto tmp = tree->root_->parent_;
        if((tmp->right_child_) == tree->root_)
          (tmp->right_child_) = tree->root_->right_child_;
        else
          (tmp->left_child_) = tree->root_->right_child_;
        (tree->root_->right_child_->parent_) = tmp;
        (tree->root_) = tree->root_->right_child_;
      }
      else {  // 要删除结点为叶节点
        if((tree->root_->parent_->left_child_) == tree->root_)
          (tree->root_->parent_->left_child_) = nullptr;
        else
          (tree->root_->parent_->right_child_) = nullptr;
      }
      return true;
    }
  }
}

#endif