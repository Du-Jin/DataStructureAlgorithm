#ifndef GRAPH_H
#define GRAPH_H

#define NOT_ADJACENT 60000    // 边权重无限大，表示顶点不

class Graph {
public:
  int FindVertex(char vertex);    // 寻找顶点在顶点集合中的索引
  int GetWeight(char vertex1, char vertex2);    // 两个相邻接顶点的边的权重
  bool IsAdjacent(char vertex1, char vertex2);    // 两个顶点是否邻接
  void DFS(int vertex_index);    // 深度遍历
  void BFS();    // 广度遍历
public:
  char *vertex_;        // 顶点集合
  int vertex_size_;
  int *adjacency_;    // 一维数组表示邻接矩阵上三角元素
  int adjacency_size_;
  bool *is_vertex_visited_;    // 对应每个顶点是否已访问

public:
  Graph() {
    vertex_ = nullptr;
    adjacency_ = nullptr;
    vertex_size_ = 0;
    adjacency_size_ = 0;
  }
  Graph(int vertex_size) {
    vertex_size_ = vertex_size;
    adjacency_size_ = vertex_size_ * (vertex_size_-1) / 2;
    vertex_ = new char(vertex_size_);
    adjacency_ = new int(adjacency_size_);
    is_vertex_visited_ = new bool(vertex_size_);
  }
  Graph(int vertex_size, char *vertex, int *adjacency) {
    vertex_size_ = vertex_size;
    adjacency_size_ = vertex_size_ * (vertex_size_-1) / 2;
    vertex_ = new char(vertex_size_);
    adjacency_ = new int(adjacency_size_);
    is_vertex_visited_ = new bool(vertex_size_);
    for(auto i = 0; i < vertex_size_; i++) {
      vertex_[i] = vertex[i];
    }
    for(auto i = 0; i < adjacency_size_; i++) {
      adjacency_[i] = adjacency[i];
    }
    for(int i = 0; i < vertex_size_; i++) {
      is_vertex_visited_[i] = false;
    }
  }
  ~Graph() {
    delete vertex_;
    delete adjacency_;
  }
};

#endif