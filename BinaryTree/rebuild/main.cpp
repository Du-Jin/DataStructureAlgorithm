/*
* 利用先序遍历结果和中序遍历结果来推导和构造二叉树结构
*/
#include <iostream>
#include <vector>
#include "binary_tree.h"

using namespace std;

int main() {
  vector<char> preorder_result_vec = {'A', 'B', 'D', 'H', 'E',
                                      'C', 'F', 'I', 'G', 'J'};
  vector<char> inorder_result_vec = {'H', 'D', 'B', 'E', 'A',
                                      'F', 'I', 'C', 'J', 'G'};
  BinaryTree<char>* tree = new BinaryTree<char>();
  RebuildTree(preorder_result_vec, inorder_result_vec, tree);

  vector<char> result_vec;
  tree->InorderTraversalStack(result_vec);
  for(auto it_begin = result_vec.begin(); it_begin != result_vec.end(); ++it_begin) {
    cout << (*it_begin) << " ";
  }
  cout << endl;
  return 0;
}
