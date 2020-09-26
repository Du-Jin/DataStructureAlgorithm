/*
* 原始希尔排序
*/

#include <iostream>

using namespace std;

int A[] = {5, 9, 3, 1, 2, 10, 4, 7, 6, -1, 8};

void ShellSort(int *array, int size) {
  for(int d = size/2; d > 0; d/=2) {    // 间隔序列
    // 浙大陈越《数据结构》教程写法
    // for(int i = d; i < size; i++) {
    //   int tmp = array[i];
    //   int j = i;
    //   for(; j >= d && array[j-d]>tmp; j-=d)
    //     array[j] = array[j-d];
    //   array[j] = tmp;
    // }

    // 自己理解希尔排序思想后写法
    for(int i = 0; i < d; i++) {    // 对d个序列依次进行插入排序
      for(int j = i+d; j < size; j+=d) {
        int tmp = array[j];    // 取出未排序序列中的第一个元素
        // 从右到左依次与已排序序列中的元素比较并右移
        int k = j;
        for(; k>=d && tmp < array[k-d]; k-=d)
          array[k] = array[k-d];
        array[k] = tmp;
      }
    }
  }
}

int main() {
  ShellSort(A, sizeof(A)/sizeof(*A));
  for(int i = 0; i < sizeof(A)/sizeof(*A); i++)
    cout << A[i] << " ";
  cout << endl;
  return 0;
}