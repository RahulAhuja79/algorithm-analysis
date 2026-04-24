#include<iostream>
#include<vector>    
using namespace std;
bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, graph, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true; 
        }
    }
    return false;
}
bool hasCycle(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, graph, visited)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    vector<vector<int>> graph = {
        {1, 2},    // Edges for vertex 0
        {0, 2},    // Edges for vertex 1
        {0, 1},    // Edges for vertex 2
        {3}        // Edges for vertex 3
    };

    if (hasCycle(graph)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}