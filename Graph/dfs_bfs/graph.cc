#include "graph.h"
#include <iostream>
#include "queue.h"

using namespace std;

int Graph::FindVertex(char vertex) {
  for(int i = 0; i < vertex_size_; i++) {
    if(vertex_[i] == vertex)
      return i;
  }
  return -1;
}

int Graph::GetWeight(char vertex1, char vertex2) {
  int vertex1_index = -1, vertex2_index = -1;
  for(int i = 0; i < vertex_size_; i++) {
    if(vertex_[i] == vertex1)
      vertex1_index = i;
    if(vertex_[i] == vertex2)
      vertex2_index = i;
  }
  if(vertex1_index == vertex2_index)
    return NOT_ADJACENT;
  // 在邻接矩阵上三角对应一级数组中寻找两个顶点的边
  int i = (vertex1_index < vertex2_index) ? vertex1_index : vertex2_index;
  int j = (vertex1_index > vertex2_index) ? vertex1_index : vertex2_index;
  int index = i * (2*vertex_size_ - i - 1) / 2 + j - i - 1;
  return adjacency_[index];
}

bool Graph::IsAdjacent(char vertex1, char vertex2) {
  return (GetWeight(vertex1, vertex2) < NOT_ADJACENT);
}

void Graph::DFS(int vertex_index) {
  // 访问该顶点
  cout << vertex_[vertex_index] << " ";
  // 蒋该顶点设置为已访问
  is_vertex_visited_[vertex_index] = true;
  // 对该顶点每个尚未访问的邻接点W递归DFS
  for(int i = 0; i < vertex_size_; i++) {
    if((IsAdjacent(vertex_[vertex_index], vertex_[i])) &&
       (!is_vertex_visited_[i]))
      DFS(i);
  }
}

void Graph::BFS() {
  // 用一个队列确保遍历次序，队列存放的是顶点的索引
  Queue<int> queue;
  queue.In(0);
  while(!(queue.IsEmpty())) {
    // 访问顶点
    int i = queue.Out();
    cout << vertex_[i] << " ";
    is_vertex_visited_[i] = true;
    // 将顶点的未被访问且不在队列内的邻接点入队
    for(int j = 0; j < vertex_size_; j++) {
      if((IsAdjacent(vertex_[i], vertex_[j])) &&      // 寻找邻接点
         (!is_vertex_visited_[j]) &&                  // 邻接点未曾访问
         (queue.IsEmpty() || !(queue.IsElementExisted(j))) // 邻接点不已在队内
      )
        queue.In(j);
    }
  }
}