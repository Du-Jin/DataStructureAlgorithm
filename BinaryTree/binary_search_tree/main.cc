#include <iostream>
#include <vector>
#include "binary_search_tree.h"

using namespace std;

int main() {
  BinarySearchTree<int> tree;
  vector<int> sequence = {8, 3, 10, 1, 6, 14, 4, 7, 13};
  Build(sequence, &tree);
  auto ptr = Search(tree.root_, 13);
  cout << ptr->data_ << endl;
  return 0;
}