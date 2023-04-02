// simple graph not-directed with weights

#include <iostream>

using namespace std;

typedef string TypeItem;

class Graph {
  private:
  int nullEdge;
  int maxVertex;
  int numVertex;
  TypeItem* vertex;
  int** adjacencyMatrix;

  public:
  Graph(int max, int nullEdgeValue);
  ~Graph();
  int obtainIndex(TypeItem item);
  bool isFull();
  void insertVertex(TypeItem item);
  void insertEdge(TypeItem exitNode, TypeItem enterNode, int weight);
  int obtainWeight(TypeItem exitNode, TypeItem enterNode);
  int obtainDegree(TypeItem item);
  void printMatrix();
  void printEdges();
};