#include <iostream>
#include "graph.h"
#include "queue.h"

using namespace std;

int main() {
  char vertex[] = {'A', 'B', 'C', 'D', 'E', 'F'};
  int adjacency[] = {1, NOT_ADJACENT, 1, 1, NOT_ADJACENT,
                      1, 1, 1, NOT_ADJACENT,
                         NOT_ADJACENT, 1, NOT_ADJACENT,
                            1, 1,
                               1};
  Graph graph(sizeof(vertex)/sizeof(*vertex), vertex, adjacency);
  bool is_adjacent = graph.IsAdjacent('A', 'A');
  cout << is_adjacent << endl;
  int weight = graph.GetWeight('A', 'A');
  cout << weight << endl;
  //graph.DFS(0);
  graph.BFS();
  return 0;
}