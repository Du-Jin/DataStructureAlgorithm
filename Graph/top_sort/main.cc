/*
 拓扑排序
*/
#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

#define N 15
#define M 60000

string vertex[N] = {"c1", "c2", "c3", "c4", "c5",
                    "c6", "c7", "c8", "c9", "c10",
                    "c11", "c12", "c13", "c14", "c15"};
int in_degree[N] = {0, 0, 2, 0, 1,
                    1, 1, 0, 1, 2,
                    2, 1, 1, 1, 1};

int edge[N][N] = {M, M, 1, M, M, M, M, M, M, M, M, M, M, M, M,
                  M, M, 1, M, M, M, M, M, M, M, M, M, 1, M, M,
                  M, M, M, M, M, M, 1, M, M, M, M, M, M, M, M,
                  M, M, M, M, 1, M, M, M, M, M, M, M, M, M, M,
                  M, M, M, M, M, 1, M, M, M, M, M, M, M, M, M,
                  M, M, M, M, M, M, M, M, M, M, M, M, M, M, 1,
                  M, M, M, M, M, M, M, M, M, 1, 1, 1, M, M, M,
                  M, M, M, M, M, M, M, M, 1, M, M, M, M, M, M,
                  M, M, M, M, M, M, M, M, M, 1, 1, M, M, M, M,
                  M, M, M, M, M, M, M, M, M, M, M, M, M, 1, M,
                  M, M, M, M, M, M, M, M, M, M, M, M, M, M, M,
                  M, M, M, M, M, M, M, M, M, M, M, M, M, M, M,
                  M, M, M, M, M, M, M, M, M, M, M, M, M, M, M,
                  M, M, M, M, M, M, M, M, M, M, M, M, M, M, M,
                  M, M, M, M, M, M, M, M, M, M, M, M, M, M, M,};

bool TopSort() {
  Queue<int> queue;
  for(int i = 0; i < N; i++)
    if(in_degree[i] == 0)
      queue.In(i);

  int cnt = 0;
  while(!queue.IsEmpty()) {
    int v = queue.Out();
    cout << vertex[v] << ' ';
    cnt++;
    for(int i = 0; i < N; i++) {
      if(edge[v][i] < M && --in_degree[i] == 0)
        queue.In(i);
    }
  }
  if(cnt != N)
    return false;
  return true;
}

int main() {
  TopSort();

  return 0;
}