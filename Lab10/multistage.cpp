#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[10][10];
    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    int mincost[10];   
    int dist[10];       

  
    mincost[n-1] = 0;

  
    for(int i = n-2; i >= 0; i--) {
        mincost[i] = INF;

        for(int j = i+1; j < n; j++) {
            if(cost[i][j] != INF) {
                if(mincost[i] > cost[i][j] + mincost[j]) {
                    mincost[i] = cost[i][j] + mincost[j];
                    dist[i] = j;
                }
            }
        }
    }

    
    cout << "\nMinimum cost: " << mincost[0];

    cout << "\nPath: ";
    int i = 0;
    cout << i+1;
    while(i != n-1) {
        i = dist[i];
        cout << " -> " << i+1;
    }

    return 0;
}