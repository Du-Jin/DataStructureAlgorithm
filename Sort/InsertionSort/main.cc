/*
* 插入排序
*/

#include <iostream>

using namespace std;

int A[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};

void InsertionSort(int *array, int size) {
  for(int i = 1; i < size; i++) {
    int tmp = array[i];
    int j = i;
    for(; j > 0 && array[j-1]>tmp; j--)
      array[j] = array[j-1];
    array[j] = tmp;
  }
}

int main() {
  InsertionSort(A, sizeof(A)/sizeof(*A));
  for(int i = 0; i < sizeof(A)/sizeof(*A); i++)
    cout << A[i] << " ";
  cout << endl;
  return 0;
}