/*
   AOE网络与关键路径问题
        比如说，最早完成时间的推导是从顶点1到顶点N，依次扫描它的入边，
        然后选择边持续时间加上前趋顶点的最早完成时间中最大的那个。
        但是如果图的工序顺序和推导顺序相悖，比如说图中顶点4先于顶点1，
        那么由于先扫描顶点1，导致顶点1扫描并选择自己入边时，顶点4的持续时间还未计算更新，
        因此导致计算错误。
        最晚期限时间的推导亦然。
*/

#include <iostream>

using namespace std;

#define N 9
#define M 60000

int earliest[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0};    // 顶点对应的最早完成时间
int latest[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0};      // 顶点对应的最晚期限时间

int c[N][N] = {M, 6, 4, 5, M, M, M, M, M,
               M, M, M, M, 1, M, M, M, M,
               M, M, M, M, 1, M, M, M, M,
               M, M, M, M, M, 2, M, M, M,
               M, M, M, M, M, M, 9, 7, M,
               M, M, M, M, M, M, M, 4, M,
               M, M, M, M, M, M, M, M, 2,
               M, M, M, M, M, M, M, M, 4,
               M, M, M, M, M, M, M, M, M};
int d[N][N];


int main() {
  // 推导各个顶点的最早完成时间
  for(int j = 1; j < N; j++) {
    // 扫描顶点j的各个入边
    int max = -1;
    for(int i = 0; i < N; i++) {
      if(c[i][j] < M && earliest[i]+c[i][j] > max) {
        max = earliest[i] + c[i][j];
      }
    }
    earliest[j] = max;
  }

  for(int i = 0; i < N; i++) {
    cout << earliest[i] << " ";
  }
  cout << endl;

  // 推导各个顶点的最晚期限时间
  latest[N-1] = earliest[N-1];
  for(int i = N-2; i >= 0; i--) {
    // 扫描顶点i的出边
    int min = M;
    for(int j = 0; j < N; j++) {
      if(c[i][j] < M && latest[j] - c[i][j] < min)
        min = latest[j] - c[i][j];
    }
    latest[i] = min;
  }

  for(int i = 0; i < N; i++)
    cout << latest[i] << " ";
  cout << endl;


  return 0;
}