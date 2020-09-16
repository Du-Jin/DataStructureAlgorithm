/*
 * 并查集
 */
#include <iostream>

using namespace std;

#define N 1000

int pre[N] = {0, 1, 2, 3, 4, 5, 6, 7};

// 查找x所属集合代表（查找过程中附带路径压缩优化）
int Find(int x) {
  // 通过递归查找所属集合代表
  int i = x;
  while(pre[i] != i)
    i = pre[i];

  // 此时查找到x所属集合的代表为i
  // 再进行路径压缩，将集合所有元素的前导结点设为i
  int j = x;
  while(j != i) {
    int tmp = pre[j];    // 暂存结点的前导结点
    pre[j] = i;
    j = tmp;
  }

  return i;
}

void Union(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if(a != b) {
    pre[a] = b;
  }
}

int main() {
  Union(0, 1);
  Union(2, 3);
  Union(3, 4);
  Union(5, 6);
  Union(6, 7);
  Union(0, 5);
  Union(0, 2);
  for(int i = 0; i < 8; i++)
    cout << pre[i] << ' ';
  cout << endl;
}
