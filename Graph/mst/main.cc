/*
* 图的最小生成树问题（Prim算法和Kruskal算法）
*/
#include <iostream>
#include <vector>

using namespace std;

#define M 60000
#define N 7    // 顶点数

char vertex[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

int edge[N][N] = {M, 2, 4, 1, M, M, M,
                  2, M, M, 3, 10, M, M,
                  4, M, M, 2, M, 5, M,
                  1, 3, 2, M, 7, 8, 4,
                  M, 10, M, 7, M, M, 6,
                  M, M, 5, 8, M, M, 1,
                  M, M, M, 4, 6, 1, M};


bool IsElementExisted(const vector<int>& v, int Element) {
  for(auto it_begin = v.begin(); it_begin < v.end(); it_begin++)
    if(*it_begin == Element)
      return true;
  return false;
}

void Prim() {
  // 存放已选取顶点(下标)
  vector<int> v;
  v.push_back(0);    // 先选取一个顶点作为树的根
  int min_edge_left = -1;
  int min_edge_right = -1;
  int min_weight = M;
  while(1) {
    // 选出树中所有顶点的所有边中权重最小的且不会形成回路（边的两端顶点都在树中）的边
    for(int i = 0; i < v.size(); i++) {
      for(int j = 0; j < N; j++) {
        if(!IsElementExisted(v, j) && (edge[v[i]][j]<min_weight)) {
          min_edge_left = v[i];
          min_edge_right = j;
          min_weight = edge[min_edge_left][min_edge_right];
        }
      }
    }
    cout << vertex[min_edge_left] << '-' << vertex[min_edge_right] << endl;
    v.push_back(min_edge_right);
    min_weight = M;
    if(v.size() == N)
      break;
  }
}

// 并查集
int root[N] = {0, 1, 2, 3, 4, 5, 6};

void Kruskal() {
  int min_weight = M;
  int min_edge_left = -1;
  int min_edge_right = -1;
  int cnt = 1;
  vector<int> v;    // 已选取的边的顶点集合
  while(cnt < N) {
    // 选出权重最小且不构成回路的边
    for(int i = 0; i < N; i++) {
      for(int j = i+1; j < N; j++) {
        if(edge[i][j] < min_weight &&
           root[i] != root[j]) {
          min_edge_left = i;
          min_edge_right = j;
          min_weight = edge[i][j];
        }
      }
    }
    cout << vertex[min_edge_left] << '-' << vertex[min_edge_right] << endl;
    min_weight = M;

    // 并查集合并（图连通）
    for(int i = 0; i < N; i++) {
      if(root[i] == root[min_edge_right]) {
        root[i] = root[min_edge_left];
      }
    }

    cnt++;
  }
}

int main() {
  //Prim();
  Kruskal();
  return 0;
}