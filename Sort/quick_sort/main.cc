/*
* 快速排序
*/
#include <iostream>

using namespace std;

int A[] = {44, 12, 59, 36, 62, 43, 94, 7, 35, 52, 1, 88, 0, -4};

void Swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

// 选取主元（头元素、尾元素、中间元素三者的中位数）
// 返回主元的位置
int Medium(int* array, int begin, int end) {
  int center = (begin + end) / 2;
  return (array[begin] < array[center] ?
            (array[center] < array[end] ? center :
              (array[begin] < array[end] ? end : begin)) :
            (array[begin] < array[end] ? begin :
              (array[end] < array[center] ? center : end)));
}

// 归并排序
void QSort(int *array, int begin, int end) {
  if(end-begin < 2) return;
  int pivot = Medium(array, begin, end);  // 选取主元
  // 以主元为界划分为小于和大于主元的两个子序列
  Swap(array[pivot], array[end]);
  int low = begin, high = end-1;
  while(1) {
    while(array[low] < array[end])
      low++;
    while(array[high] > array[end])
      high--;
    if(low < high)
      Swap(array[low], array[high]);
    else
      break;
  }
  Swap(array[low], array[end]);
  // 对两个子序列递归进行快速排序
  QSort(array, begin, low-1);
  QSort(array, low+1, end);
}

// 归并排序更友好的接口
void QuickSort(int *array, int size) {
  QSort(array, 0, size-1);
}

int main() {
  int size = sizeof(A)/sizeof(*A);
  QuickSort(A, size);
  for(int i = 0; i < size; i++)
    cout << A[i] << " ";
  cout << endl;
  return 0;
}