/*
* 二叉树的同构
* 输入两个二叉树的信息，判断这两个二叉树是否同构
*/

#include <iostream>
#include "binary_tree.h"

using namespace std;

int main() {
  ArrayNode array1[8] = {ArrayNode('G','-','H'), ArrayNode('B','E','D'),
                         ArrayNode('F','-','-'), ArrayNode('A','C','B'),
                         ArrayNode('H','-','-'), ArrayNode('C','G','-'),
                         ArrayNode('D','-','-'), ArrayNode('E','F','-')};
  ArrayNode array2[8] = {ArrayNode('A','B','C'), ArrayNode('B','D','E'),
                         ArrayNode('C','-','G'), ArrayNode('D','-','-'),
                         ArrayNode('E','-','F'), ArrayNode('F','-','-'),
                         ArrayNode('G','H','-'), ArrayNode('H','-','-')};
  ArrayNode array3[3] = {ArrayNode('B','D','-'), ArrayNode('E','-','-'),
                         ArrayNode('D','-','E')};
  ArrayNode array4[8] = {ArrayNode('A','B','C'), ArrayNode('B','D','E'),
                         ArrayNode('C','-','G'), ArrayNode('D','-','-'),
                         ArrayNode('E','-','H'), ArrayNode('F','-','-'),
                         ArrayNode('G','F','-'), ArrayNode('H','-','-')};

  // 测试根据输入信息构造二叉树的功能
  // auto result_tree = RebuildBinayTree(array1, 8);
  // vector<char> result_vec;
  // result_tree->LevelOrderTraversal(result_vec);
  // for(auto it_begin = result_vec.begin(); it_begin != result_vec.end();
  //     it_begin++) {
  //   cout << *it_begin << " ";
  // }
  // cout << endl;

  auto tree1 = RebuildBinaryTree(array1, 8);
  auto tree2 = RebuildBinaryTree(array2, 8);
  auto tree3 = RebuildBinaryTree(array3, 3);
  auto tree4 = RebuildBinaryTree(array4, 8);
  cout << IsIsomorphic(tree1, tree2) << endl;
  return 0;
}