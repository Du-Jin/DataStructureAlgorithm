/*
* 归并排序
*/
#include <iostream>

using namespace std;

int A[] = {44, 12, 59, 36, 62, 43, 94, 7, 35, 52, 1, 88, 0, -4};

// 归并子列
// 将用来暂存归并后数据的内存作为参数传进来是为了避免反复申请和释放内存
void Merge(int* array, int* tmp, int left_begin,
           int right_begin, int right_end) {
  int left_ptr = left_begin, right_ptr = right_begin, tmp_ptr = left_begin;
  while(left_ptr <= right_begin-1 && right_ptr <= right_end) {
    if(array[left_ptr] < array[right_ptr])
      tmp[tmp_ptr++] = array[left_ptr++];
    else
      tmp[tmp_ptr++] = array[right_ptr++];
  }
  while(left_ptr <= right_begin-1)
    tmp[tmp_ptr++] = array[left_ptr++];
  while(right_ptr <= right_end)
    tmp[tmp_ptr++] = array[right_ptr++];
  for(int i = left_begin; i <= right_end; i++)
    array[i] = tmp[i];
}

// // 归并排序的递归实现
// void MSort(int *array, int *tmp, int left_begin, int right_end) {
//   if(left_begin < right_end) {
//     int center = (left_begin + right_end) / 2;
//     MSort(array, tmp, left_begin, center);
//     MSort(array, tmp, center+1, right_end);
//     Merge(array, tmp, left_begin, center+1, right_end);
//   }
// }

// // 归并排序更友好的接口
// void MergeSort(int *array, int size) {
//   int* tmp = new int[size];
//   MSort(array, tmp, 0, size-1);
//   delete []tmp;
// }

// 归并排序的非递归实现
void MergeSort(int *array, int size) {
  int *tmp = new int[size];
  for(int length = 1; length < size; length*=2) {
    int left_begin = 0;
    for(; left_begin + 2*length-1 < size;
        left_begin += 2*length)
      Merge(array, tmp, left_begin, left_begin+length, left_begin+2*length-1);
    if(left_begin+length < size)    // 剩下1个子列但不足两个子列
      Merge(array, tmp, left_begin, left_begin+length, size-1);
    //else                            // 剩下不足1个子列
      // do nothing
  }
  delete tmp;
}

int main() {
  int size = sizeof(A)/sizeof(*A);
  MergeSort(A, size);
  for(int i = 0; i < size; i++)
    cout << A[i] << " ";
  cout << endl;
  return 0;
}
