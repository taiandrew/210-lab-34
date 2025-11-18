// COMSC 210 | Lab 34 | 17 Nov 2025
// IDE: VS Code

#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <queue>

#include "graph.h"

using namespace std;

// Fn prototypes
void DFS(Graph const &graph, int v);
void BFS(Graph const &graph, int v);

/*
Graph's adjacency list:
0 --> (1, 12) (2, 8) (3, 21) 
1 --> (0, 12) 
2 --> (0, 8) (3, 6) (6, 2) (4, 4) (5, 5) 
3 --> (0, 21) (2, 6) 
4 --> (5, 9) (2, 4) 
5 --> (6, 6) (4, 9) (2, 5) 
6 --> (2, 2) (5, 6) 

Graph 2's adjacency list:
0 --> (1, 8) (2, 21)
1 --> (0, 8) (2, 6) (3, 5) (4, 4)
2 --> (0, 21) (1, 6) (7, 11) (8, 8)
3 --> (1, 5) (4, 9)
4 --> (1, 4) (3, 9)
5 --> (6, 10) (7, 15) (8, 5)
6 --> (5, 10) (7, 3) (8, 7)
7 --> (6, 3) (5, 15) (2, 11)
8 --> (5, 5) (6, 7) (2, 8)
DFS starting from vertex 0:
0 2 8 6 5 7 1 4 3
BFS starting from vertex 0:
0 1 2 3 4 7 8 6 5

*/

// --------
// Main
// --------
int main() {
    // Initialize edges
    vector<Edge> edges = {
        {0, 1, 12}, {0, 2, 8}, {0, 3, 21},
        {2, 3, 6}, {2, 4, 4}, {2, 5, 5},
        {5, 6, 6}, {4, 5, 9}, {2, 6, 2}
    };

    Graph graph(edges);
    graph.printGraph();

    // DFS and BFS of original graph
    cout << "Depth First Search starting from vertex 0: ";
    DFS(graph, 0);
    cout << endl;

    cout << "Breadth First Search starting from vertex 0: ";
    BFS(graph, 0);
    cout << endl;

    // Initialize edges for graph 2
    vector<Edge> edges2 = {
        {0, 1, 8}, {0, 2, 21},
        {1, 2, 6}, {1, 3, 5}, {1, 4, 4},
        {3, 4, 9},
        {5, 6, 10}, {5, 7, 15}, {5, 8, 5},
        {6, 7, 3}, {6, 8, 7},
        {2, 7, 11}, {2, 8, 8}
    };

    Graph graph2(edges2);
    graph2.printGraph();

    // DFS and BFS of graph 2
    cout << "Depth First Search starting from vertex 0: ";
    DFS(graph2, 0);
    cout << endl;

    cout << "Breadth First Search starting from vertex 0: ";
    BFS(graph2, 0);
    cout << endl;

    return 0;
}

// --------
// Functions
// --------

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

// BFS implementation via recursion
// implement using queue
void BFS(Graph const &graph, int v) {
    vector<bool> discovered(graph.adjList.size(), false);
    queue<int> queue;

    // mark the source vertex as discovered
    discovered[v] = true;
    queue.push(v);

    while (!queue.empty()) {
        // dequeue front vertex and print it
        v = queue.front();
        queue.pop();
        cout << v << " ";

        // do for every edge (v, u)
        for (auto &u : graph.adjList[v]) {
            if (!discovered[u.first]) {
                // mark it as discovered and enqueue it
                discovered[u.first] = true;
                queue.push(u.first);
            }
        }
    }
}