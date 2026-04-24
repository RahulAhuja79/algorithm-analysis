#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };

    int n = graph.size();
    vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX));
    dp[1][0] = 0;
    for(int mask=1; mask<(1<<n); mask++){
        for(int u=0; u<n; u++){
            if((mask & (1<<u)) && dp[mask][u] != INT_MAX){
                for(int v=0; v<n; v++){
                    if(!(mask & (1<<v)) && graph[u][v] != 0){
                        dp[mask | (1<<v)][v] = min(dp[mask | (1<<v)][v], dp[mask][u] + graph[u][v]);
                    }
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        if(dp[(1<<n)-1][i] != INT_MAX && graph[i][0] != 0){
            ans = min(ans, dp[(1<<n)-1][i] + graph[i][0]);
        }
    }
    cout << "Minimum cost of visiting all cities and returning to the starting point: " << ans << endl;

    return 0;
}
