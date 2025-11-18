#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;  // Creates an alias 'Pair' for the pair<int,int> data type
                              // so below we can use vector<Pair> rather than vector<pair<int, int>>
class Graph {
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;
    // constructor
    Graph(vector<Edge> const &edges) {

        // resize the vector to hold SIZE elements of type vector<Edge>
        // Find the maximum numbered vertex
        int maxVertex = 0;
        for (auto &edge : edges) {
            maxVertex = max(maxVertex, max(edge.src, edge.dest));
        }
        adjList.resize(maxVertex + 1);

        // add edges to the directed graph
        for (auto &edge: edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;
            adjList[src].push_back(make_pair(dest, weight));
            adjList[dest].push_back(make_pair(src, weight));
        }
    }
    void printGraph() {
        for (int i = 0; i < adjList.size(); i++) {
            for (Pair v: adjList[i])
                cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
            cout << endl;
        }
    }
};

#endif