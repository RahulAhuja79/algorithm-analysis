#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

struct Edge {
    int src, dest, weight;
};

int parent[MAX];


int findParent(int x) {
    while (parent[x] > 0)
        x = parent[x];
    return x;
}


void makeUnion(int a, int b) {
    parent[b] = a;
}


bool sortByWeight(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {

    int n, e;
    cout << "Enter vertices and edges: ";
    cin >> n >> e;

    Edge edges[MAX];

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    sort(edges, edges + e, sortByWeight);

    
    for (int i = 1; i <= n; i++)
        parent[i] = -1;

    int edgesUsed = 0;
    int totalCost = 0;

    cout << "MST edges:\n";

    for (int i = 0; i < e && edgesUsed < n - 1; i++) {

        int u = edges[i].src;
        int v = edges[i].dest;

        int p1 = findParent(u);
        int p2 = findParent(v);

        if (p1 != p2) {
            cout << u << " - " << v << " : " << edges[i].weight << endl;
            totalCost += edges[i].weight;

            makeUnion(p1, p2);
            edgesUsed++;
        }
    }

    cout << "Total cost = " << totalCost;

    return 0;
}