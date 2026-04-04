#include <iostream>
using namespace std;

#define INF 999
#define MAX 100

int main() {

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[MAX][MAX];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    int near[MAX];        // nearest vertex
    int result[MAX][2];   // edges of MST
    int totalCost = 0;

    int u = 0, v = 0;
    int minVal = INF;

    // find minimum edge in whole matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] < minVal) {
                minVal = graph[i][j];
                u = i;
                v = j;
            }
        }
    }

    result[0][0] = u;
    result[0][1] = v;
    totalCost = graph[u][v];

    // initialize near array
    for (int i = 0; i < n; i++) {
        if (graph[i][u] < graph[i][v])
            near[i] = u;
        else
            near[i] = v;
    }

    near[u] = near[v] = -1;

    // remaining edges
    for (int i = 1; i < n - 1; i++) {

        int minEdge = INF;
        int idx = -1;

        for (int j = 0; j < n; j++) {
            if (near[j] != -1 && graph[j][near[j]] < minEdge) {
                minEdge = graph[j][near[j]];
                idx = j;
            }
        }

        result[i][0] = idx;
        result[i][1] = near[idx];
        totalCost += graph[idx][near[idx]];

        near[idx] = -1;

        // update near array
        for (int j = 0; j < n; j++) {
            if (near[j] != -1 && graph[j][near[j]] > graph[j][idx]) {
                near[j] = idx;
            }
        }
    }

    cout << "MST Edges:\n";
    for (int i = 0; i < n - 1; i++) {
        cout << result[i][0] << " - " << result[i][1] << endl;
    }

    cout << "Minimum Cost = " << totalCost;

    return 0;
}