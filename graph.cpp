#include <iostream>
#include "graph.h"

using namespace std;



Graph::Graph(int max, int nullEdgeValue)
{
  numVertex = 0;
  maxVertex = max;
  nullEdgeValue = nullEdgeValue;

  vertex = new TypeItem[maxVertex];

  adjacencyMatrix = new int*[maxVertex];
  for (int i = 0; i < maxVertex; i++) {
    adjacencyMatrix[i] = new int[maxVertex];
  }
  for (int i = 0; i < maxVertex; i++) {
    for (int j = 0; j < maxVertex; j++) {
      adjacencyMatrix[i][j] = nullEdge;
    }
  }
}

Graph::~Graph()
{
  delete [] vertex;
  for (int i = 0; i < maxVertex; i++) {
    delete [] adjacencyMatrix[i];
  }
  delete [] adjacencyMatrix;
}

int Graph::obtainIndex(TypeItem item)
{
  int index = 0;
  while (item != vertex[index]) {
    index++;
  }
  if (item == vertex[index]){
    return index;
  } else {
    return -1;
  }
}

bool Graph::isFull()
{
  return numVertex == maxVertex;
}

void Graph::insertVertex(TypeItem item)
{
  if (isFull()) {
    cout << "max vertex was reached \n";
  } else {
    vertex[numVertex] = item;
    numVertex++;
  }
}

void Graph::insertEdge(TypeItem exitNode, TypeItem enterNode, int weight)
{
  int line = obtainIndex(exitNode);
  int column = obtainIndex(enterNode);

  adjacencyMatrix[line][column] = weight;
  adjacencyMatrix[column][line] = weight; // remove if graph is directed
}

int Graph::obtainWeight(TypeItem exitNode, TypeItem enterNode)
{
  int line = obtainIndex(exitNode);
  int column = obtainIndex(enterNode);
  return adjacencyMatrix[line][column];
}

int Graph::obtainDegree(TypeItem item)
{
  int line = obtainIndex(item);
  int degree = 0;
  for (int i = 0; i < maxVertex; i++) {
    if (adjacencyMatrix[line][i] != nullEdge) {
      degree++;
    }
  }
  return degree;
}

void Graph::printMatrix()
{
  cout << "adjacencyMatrix:\n ";
  for (int i = 0; i < maxVertex; i++) {
    for (int j = 0; j < maxVertex; j++) {
      cout << adjacencyMatrix[i][j] << " ";
    }
    cout << endl;
  }
}

void Graph::printEdges()
{
  cout << "Edge list: \n";
  for (int i = 0; i < numVertex; i++) {
    cout << i << ": " << vertex[i] << endl;
  }
}