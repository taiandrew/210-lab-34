#include <iostream>
#include <vector>
#include <utility>

#include "graph.h"

using namespace std;

/*
Graph's adjacency list:
0 --> (1, 12) (2, 8) (3, 21) 
1 --> (0, 12) 
2 --> (0, 8) (3, 6) (6, 2) (4, 4) (5, 5) 
3 --> (0, 21) (2, 6) 
4 --> (5, 9) (2, 4) 
5 --> (6, 6) (4, 9) (2, 5) 
6 --> (2, 2) (5, 6) 
*/

int main() {
    // Initialize edges
    vector<Edge> edges = {
        {0, 1, 12}, {0, 2, 8}, {0, 3, 21},
        {2, 3, 6}, {2, 4, 4}, {2, 5, 5},
        {5, 6, 6}, {4, 5, 9}, {2, 6, 2}
    };

    Graph graph(edges);
    graph.printGraph();

    return 0;
}
