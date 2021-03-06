/*
* 二叉树的层序遍历——队列实现
*/

#include <iostream>
#include "binary_tree.h"

using namespace std;

int main() {
  BinaryTreeNode<char> h('H');
  BinaryTreeNode<char> i('I');
  BinaryTreeNode<char> j('J');
  BinaryTreeNode<char> d('D');
  BinaryTreeNode<char> e('E');
  BinaryTreeNode<char> f('F');
  BinaryTreeNode<char> g('G');
  BinaryTreeNode<char> b('B');
  BinaryTreeNode<char> c('C');
  BinaryTreeNode<char> a('A');

  BinaryTree<char> tree_h(&h);
  BinaryTree<char> tree_i(&i);
  BinaryTree<char> tree_j(&j);
  BinaryTree<char> tree_d(&d);
  BinaryTree<char> tree_e(&e);
  BinaryTree<char> tree_f(&f);
  BinaryTree<char> tree_g(&g);
  BinaryTree<char> tree_b(&b);
  BinaryTree<char> tree_c(&c);
  BinaryTree<char> tree_a(&a);

  tree_d.Insert(&tree_h, LEFT);
  tree_f.Insert(&tree_i, RIGHT);
  tree_g.Insert(&tree_j, LEFT);
  tree_b.Insert(&tree_d, LEFT);
  tree_b.Insert(&tree_e, RIGHT);
  tree_c.Insert(&tree_f, LEFT);
  tree_c.Insert(&tree_g, RIGHT);
  tree_a.Insert(&tree_b, LEFT);
  tree_a.Insert(&tree_c, RIGHT);

  cout << "height = " << CalHeight(tree_a.root_) << endl;

  return 0;
}