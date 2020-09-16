#include <iostream>
#include "heap.h"
#include "huffman_tree.h"

using namespace std;

int main() {
  int weight[5] = {1, 2, 3, 4, 5};
  HuffmanTreeNode tree = BuildHuffmanTree(weight, 5);
  cout << tree.weight_ << endl;
  return 0;
}