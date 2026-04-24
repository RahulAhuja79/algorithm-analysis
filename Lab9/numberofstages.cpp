#include<iostream>
#include<vector>    
using namespace std;
int countStages(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }
    int stages = 0;
    while (true) {
        vector<int> zeroInDegree;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                zeroInDegree.push_back(i);
            }
        }
        if (zeroInDegree.empty()) break;
        stages++;
        for (int node : zeroInDegree) {
            inDegree[node] = -1; 
            for (int neighbor : graph[node]) {
                inDegree[neighbor]--;
            }
        }
    }
    return stages;
} 
int main() {
    vector<vector<int>> graph = {
        {1, 2},    // Edges for vertex 0
        {3},       // Edges for vertex 1
        {3},       // Edges for vertex 2
        {}         // Edges for vertex 3
    };

    int stages = countStages(graph);
    cout << "Number of stages in the multistage graph: " << stages << endl;

    return 0;
}