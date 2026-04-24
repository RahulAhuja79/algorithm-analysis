#include <iostream>
#include <vector>   
#include <queue>
#include <climits>
using namespace std;


void dijkstra(vector<vector<pair<int, int>>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    
    cout << "Vertex\tDistance from Source\tPath" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t\t";
        if (dist[i] == INT_MAX) {
            cout << "No path" << endl;
        } else {
            vector<int> path;
            for (int v = i; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            for (size_t j = 0; j < path.size(); j++) {
                cout << path[j];
                if (j < path.size() - 1) cout << " -> ";
            }
            cout << endl;
        }
    }
}
int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 1}},    // Edges for vertex 0
        {{0, 4}, {2, 2}, {3, 5}}, // Edges for vertex 1
        {{0, 1}, {1, 2}, {3, 8}}, // Edges for vertex 2
        {{1, 5}, {2, 8}}     // Edges for vertex 3
    };

    int source = 0;
    dijkstra(graph, source);

    return 0;
}