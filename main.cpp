#include <iostream>
#include <vector>
#include <utility>
#include <stack>

#include "graph.h"

using namespace std;

// Fn prototypes
void DFS(Graph const &graph, int v, vector<bool> &discovered);
void DFS(Graph const &graph, int v);

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

    cout << "Depth First Search (starting from vertex 0): ";
    DFS(graph, 0);
    cout << endl;

    

    return 0;
}


// DFS implementation via recursion
// implement using a stack
void DFS(Graph const &graph, int v) {
    vector<bool> discovered(graph.adjList.size(), false);
    stack<int> stack;

    // push the source vertex into the stack
    stack.push(v);
    discovered[v] = true;

    while (!stack.empty()) {
        // pop a vertex from the stack
        int v = stack.top();
        stack.pop();
        cout << v << " ";

        // do for every edge (v, u)
        for (auto &u : graph.adjList[v]) {
            if (!discovered[u.first]) {
                // mark it as discovered and push it into the stack
                discovered[u.first] = true;
                stack.push(u.first);
            }
        }
    }
}