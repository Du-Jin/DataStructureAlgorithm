/*
* 选择排序
*/

#include <iostream>

using namespace std;

int A[] = {5, 9, 3, 1, 2, 10, 4, 7, 6, -1, 8};

void SelectionSort(int* array, int size) {
  for(int i = 0; i < size; i++) {
    // 选出未排序部分最小元素
    int min_position = i;
    for(int j = i+1; j < size; j++)
      if(array[j] < array[min_position])
        min_position = j;

    // 将选出的最小元素放到已排序部分最后面
    int tmp = array[i];
    array[i] = array[min_position];
    array[min_position] = tmp;
  }
}

int main() {
  SelectionSort(A, sizeof(A)/sizeof(*A));
  for(int i = 0; i < sizeof(A)/sizeof(*A); i++)
    cout << A[i] << " ";
  cout << endl;
  return 0;
}