#include <iostream>
#include <vector>
using namespace std;
#define INF 9999

void route(vector<vector<int>> &next, int i, int j) {
    if (next[i][j] == -1) {
        cout << "No path";
        return;
    }
    vector<int> path;
    while (i != j) {
        path.push_back(i);
        i = next[i][j];
    }
    path.push_back(j);
    for (size_t k = 0; k < path.size(); k++) {
        cout << path[k];
        if (k != path.size() - 1)
            cout << " -> ";
    }
}

void shortestpath(vector<vector<int>> &dist, vector<vector<int>> &next) {
    int n = dist.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> next(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        next[u][v] = v;
    }

    shortestpath(dist, next);

    cout << "\nShortest paths between all pairs:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    int src, dest;
    cout << "\nEnter source and destination to print route: ";
    cin >> src >> dest;
    route(next, src, dest);
    cout << endl;

    return 0;
}