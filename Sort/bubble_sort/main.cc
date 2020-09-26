/*
* 冒泡排序
*/

#include <iostream>

using namespace std;

int A[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};

void Swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void BubbleSort(int *array, int size) {
  for(auto i = 1; i < size; i++) {
    bool flag = true;
    for(auto j = 0; j < size-i; j++) {
      if(array[j] > array[j+1]) {
        Swap(array[j], array[j+1]);
        flag = false;
      }
    }
    if(flag)    // 当一轮循环中始终没有交换，说明已符合顺序，则退出循环
      break;
  }
}

int main() {
  BubbleSort(A, sizeof(A)/sizeof(*A));
  for(auto i = 0; i < sizeof(A)/sizeof(*A); i++)
    cout << A[i] << ' ';
  cout << endl;
  return 0;
}