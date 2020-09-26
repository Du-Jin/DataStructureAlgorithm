/*
* 堆排序
*/

#include <iostream>
#include "heap.h"

using namespace std;

int A[] = {5, 9, 3, 1, 2, 10, 4, 7, 6, -1, 8};

// 简单做法
// void HeapSort(int *array, int size) {
//   Heap<int>* min_heap = MinHeapBuild(array, size);
//   int *tmp = new int(size);
//   for (int i = 0; i < size; i++)
//     tmp[i] = min_heap->MinHeapDelete();
//   for (int i = 0; i < size; i++)
//     array[i] = tmp[i];
// }

// 将N个元素的树数组以array[r]为根的子堆调整为最大堆
void PercolateDown(int *array, int r , int size) {
  int tmp = array[r];
  int parent = r, child = 2*parent+1;
  for(; 2*parent+1 < size; parent = child, child = 2*parent+1) {
    // 找出左右子节点中较大的那个（如果右子节点存在）
    if((child < size-1) && (array[child+1] > array[child]))
      child++;
    if(tmp > array[child])
      break;               // 已找到合适的位置
    else
      array[parent] = array[child];
  }
  array[parent] = tmp;
}

void Swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

// 堆排序
void HeapSort(int *array, int size) {
  // 建立最大堆
  for(int i = size/2-1; i>=0; i--)
    PercolateDown(array, i, size);
  // 迭代将最大元素移到末尾
  for(int i = size-1; i >0; i--) {
    Swap(array[0], array[i]);    // 将剩余部分最大元素交换到末尾
    PercolateDown(array, 0, i);  // 将剩余元素重整为最大堆
  }
}


int main() {
  //HeapSort(A, sizeof(A)/sizeof(*A));
  int size = sizeof(A)/sizeof(*A);
  HeapSort(A, size);
  for(int i = 0; i < size; i++)
    cout << A[i] << " ";
  cout << endl;
  return 0;
}