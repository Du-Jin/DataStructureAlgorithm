#include "heap.h"
#include "huffman_tree.h"

using namespace std;

bool operator<(const HuffmanTreeNode& a, const HuffmanTreeNode& b) {
  return a.weight_ < b.weight_;
}

HuffmanTreeNode BuildHuffmanTree(int *weight, int size) {
  Heap<HuffmanTreeNode> *heap = new Heap<HuffmanTreeNode>(size);
  for(int i = 0; i < size; i++)
    heap->head_[i].weight_ = *(weight+i);

  while(heap->size_ > 1) {
    static HuffmanTreeNode node;
    static HuffmanTreeNode left_node = heap->MinHeapDelete();
    static HuffmanTreeNode right_node = heap->MinHeapDelete();
    node.left_ = &left_node;
    node.right_ = &right_node;
    node.weight_ = node.left_->weight_ + node.right_->weight_;
    heap->MinHeapInsert(node);
  }
  static HuffmanTreeNode node = heap->MinHeapDelete();
  //delete heap;
  return node;
}