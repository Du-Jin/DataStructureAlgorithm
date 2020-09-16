/*
  堆的建立、插入、删除
*/
#include <iostream>
#include "heap.h"

using namespace std;

int main() {
  int data[12] = {79, 66, 43, 83, 30, 87, 38, 55, 91, 72, 49, 9};
  Heap<int> *heap = MaxHeapBuild(data, 12);
  // heap->MaxHeapInsert(100);
  // cout << heap->MaxHeapDelete() << endl;

  for(int i = 0; i < heap->size_; i++) {
    cout << heap->head_[i] << " ";
  }
  cout << endl;

  return 0;
}