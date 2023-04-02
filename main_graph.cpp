#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
  int max, nullEdgeValue;
  cout << "type max quantity of edges: \n";
  cin >> max;
  cout << "type value to represent absense of edges: \n";
  cin >> nullEdgeValue;
  Graph graph1(max, nullEdgeValue);
  TypeItem item1, item2;
  int option, value, weight;

  do {
    cout << "type 0 to stop algorithm \n";
    cout << "type 1 to insert vertex\n";
    cout << "type 2 to insert edge\n";
    cout << "type 3 to print degree of vertex\n";
    cout << "type 4 to print weight of edge\n";
    cout << "type 5 to print adjacencyMatrix\n";
    cout << "type 6 to print vertex list\n";
    cin >> option;

    if (option == 1) {
      cout << "type element of vertex that will be inserted:\n";
      cin >> item1;
      graph1.insertVertex(item1);
    } else if (option == 2) {
      cout << "type exit vertex\n";
      cin >> item1;
      cout << "type enter vertex\n";
      cin >> item2;
      cout << "type weight of edge\n";
      cin >> weight;
      graph1.insertEdge(item1, item2, weight);
    } else if (option == 3) {
      cout << "type vertex to calculate degree\n";
      cin >> item1;
      value = graph1.obtainDegree(item1);
      cout << "degree is: " << value << endl;
    } else if (option == 4) {
      cout << "type exit vertex\n";
      cin >> item1;
      cout << "type enter vertex\n";
      cin >> item2;
      value = graph1.obtainWeight(item1, item2);
      cout << "weight of this edge is: " << value << endl;
    } else if (option == 5) {
      graph1.printMatrix();
    } else if (option == 6) {
      graph1.printEdges();
    }
  } while (option != 0);
  return 0;
}