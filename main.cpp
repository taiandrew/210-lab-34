// COMSC 210 | Lab 34 | 17 Nov 2025
// IDE: VS Code

#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <functional>
#include <climits>

#include "graph.h"

using namespace std;

// Fn prototypes
void DFS(Graph const &graph, int v);
void BFS(Graph const &graph, int v);
void testDriver();

void printTexts(Graph const &graph);
void DFSTexts(Graph const &graph, int start);
void BFSTexts(Graph const &graph, int start);
// Note: don't really have a sensible application with the text theme, but functions
void shortestPath(Graph const &graph, int start);
void minimumSpanningTree(Graph const &graph);

int menuTexts();


// --------
// Main
// --------
int main() {

    //testDriver();

    // Initialize edges for graph
    vector<Edge> edges = {
        {0, 1, 8}, {0, 2, 21},
        {1, 2, 6}, {1, 3, 5}, {1, 4, 4},
        {3, 4, 9},
        {5, 6, 10}, {5, 7, 15}, {5, 8, 5},
        {6, 7, 3}, {6, 8, 7},
        {2, 7, 11}, {2, 8, 8}
    };

    Graph graph(edges);

    /*
    // Print text message connections
    printTexts(graph);
    // Perform DFS themed as information spread
    DFSTexts(graph, 0);
    // Perform BFS themed as layer-by-layer inspection
    BFSTexts(graph, 0);
    // Compute shortest paths from node 0
    shortestPath(graph, 0);
    // Compute minimum spanning tree from node 0
    minimumSpanningTree(graph, 0);
    */
    int choice;
    
    do {
        choice = menuTexts();
        switch (choice) {
            case 1:
                printTexts(graph);
                break;
            case 2:
                cout << "Which person to start from? ";
                int startPerson;
                cin >> startPerson;
                DFSTexts(graph, startPerson);
                break;
            case 3:
                cout << "Which person to start from? ";
                cin >> startPerson;
                BFSTexts(graph, startPerson);
                break;
            case 4:
                cout << "Which person to start from? ";
                cin >> startPerson;
                shortestPath(graph, startPerson);
                break;
            case 5:
                cout << "Which person to start from? ";
                cin >> startPerson;
                minimumSpanningTree(graph, startPerson);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Exiting." << endl;
                break;
        }
   } while (choice != 6);

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


void testDriver() {
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
    */

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


}

void printTexts(Graph const &graph) {
    cout << "Text messages sent/received between people:" << endl;
    cout << "================================" << endl;

    for (int i = 0; i < graph.adjList.size(); i++) {
        // Print header for each person
        cout << "Person " << i << " connects to:" << endl;
        
        // Print all connections from this person
        for (auto &v : graph.adjList[i]) {
            cout << "  → Person " << v.first << " (Texts: " << v.second << ")" << endl;
        }
        cout << endl; // Blank line for readability
    }
}

void DFSTexts(Graph const &graph, int start) {
    vector<bool> discovered(graph.adjList.size(), false);
    stack<int> stack;

    cout << "Network Trace (DFS) from Person " << start << " :" << endl;
    cout << "Purpose: Tracking possible information spread through the network." << endl;
    cout << "=======================================" << endl;

    // The starting point
    cout << "Person " << start << endl;

    // Initialize DFS
    discovered[start] = true;
    stack.push(start);

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        cout << "From Person " << v << ":" << endl;
        
        // Iterate over all adjacent nodes (potential spread points)
        for (auto &u : graph.adjList[v]) {
            if (!discovered[u.first]) {
                discovered[u.first] = true;
                
                // Print themed connection status
                cout << "  → Potential spread to Person " << u.first
                     << " - Texts: " << u.second << endl;

                stack.push(u.first);
            }
        }
        // Add an empty line after finishing each person's neighbors
        cout << endl;
    }
}

void BFSTexts(Graph const &graph, int start) {
    vector<bool> discovered(graph.adjList.size(), false);
    queue<int> queue;

    cout << "Layer-by-Layer Network Inspection (BFS) from Person " << start << ":" << endl;
    cout << "Purpose: Analyzing info spread by distance from source" << endl;
    cout << "=================================================" << endl;

    // Start BFS
    discovered[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();

        cout << "Checking Person " << v << endl;

        // Explore all adjacent people
        for (auto &u : graph.adjList[v]) {
            if (!discovered[u.first]) {
                discovered[u.first] = true;
                queue.push(u.first);

                cout << "  → Next: Person " << u.first
                     << " - Texts: " << u.second << endl;
            }
        }
        cout << endl;  // Blank line between layers
    }
}


void shortestPath(Graph const &graph, int start) {
    int n = graph.adjList.size();
    const int INF = INT_MAX;

    // dist[i] = shortest distance from start to i
    vector<int> dist(n, INF);
    dist[start] = 0;

    // Min-heap priority queue: (distance, node)
    typedef pair<int, int> P;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, start));

    while (!pq.empty()) {
        P current = pq.top();
        pq.pop();

        int d = current.first;
        int u = current.second;

        // If we already found a better path, skip
        if (d > dist[u]) continue;

        // Relax edges out of u
        for (auto const &edge : graph.adjList[u]) {
            int v = edge.first;      // neighbor
            int w = edge.second;     // weight

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(P(dist[v], v));
            }
        }
    }

    // Print results
    cout << "Shortest path from node " << start << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cout << start << " -> " << i << " : ";
        if (dist[i] == INF) {
            cout << "INF";
        } else {
            cout << dist[i];
        }
        cout << endl;
    }
}

void minimumSpanningTree(Graph const &graph) {
    int n = graph.adjList.size();
    const int INF = INT_MAX;

    // Prim's arrays
    vector<int> key(n, INF);        // smallest edge weight to connect v
    vector<int> parent(n, -1);      // parent of v in MST
    vector<bool> inMST(n, false);   // whether v is already in MST

    using P = pair<int,int>;        // (key, vertex)
    priority_queue<P, vector<P>, greater<P>> pq;

    // Handle possibly disconnected graphs:
    // run Prim starting from every vertex not yet in MST
    for (int start = 0; start < n; ++start) {
        if (inMST[start]) continue;

        // start a new tree
        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            // relax edges from u
            for (auto const &edge : graph.adjList[u]) {
                int v = edge.first;
                int w = edge.second;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
    }

    // Print MST (or forest) edges
    cout << "Minimum Spanning Tree (overall):" << endl;

    int totalWeight = 0;
    for (int v = 0; v < n; ++v) {
        if (parent[v] == -1) {
            // root of a tree (could be isolated or a component root)
            cout << "root: " << v << " : 0" << endl;
        } else {
            cout << parent[v] << " - " << v << " : " << key[v] << endl;
            totalWeight += key[v];
        }
    }

    cout << "Total weight of MST/forest: " << totalWeight << endl;
}

int menuTexts() {
    cout << endl;
    cout << "Menu Options:" << endl;
    cout << "1. Display text network edges" << endl;
    cout << "2. Track information paths from source (DFS)" << endl;
    cout << "3. Check information spread from source (BFS)" << endl;
    cout << "4. Compute Shortest Paths from a Person" << endl;
    cout << "5. Compute Minimum Spanning Tree of the Network" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice (1-6): ";
    int choice;
    cin >> choice;
    return choice;
}