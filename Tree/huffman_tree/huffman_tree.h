#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "heap.h"
#include <memory>

using namespace std;

class HuffmanTreeNode {
public:
  int weight_;
  HuffmanTreeNode* left_;
  HuffmanTreeNode* right_;
public:
  HuffmanTreeNode() {
    weight_ = 0;
    left_ = nullptr;
    right_ = nullptr;
  }
  HuffmanTreeNode(int weight) {
    weight_ = weight;
    left_ = nullptr;
    right_ = nullptr;
  }

public:
  friend bool operator<(const HuffmanTreeNode& a, const HuffmanTreeNode& b);
};

class HuffmanTree {
public:
  HuffmanTreeNode* root_;

public:
  HuffmanTree() {
    root_ = nullptr;
  }
};

// 参数：权值数组（假设已经从小到大排序好）
HuffmanTreeNode BuildHuffmanTree(int *weight, int size);

#endif