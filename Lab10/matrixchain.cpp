#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int, vector<vector<int>>> matrixChain(const vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
    
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                M[i][j] = min(M[i][j], cost);
                s[i][j] = k;

            }
        }
    }

    return {M[1][n], s} ;
}

void print(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    print(s, i, s[i][j]);
    print(s, s[i][j] + 1, j);
    cout << ")";
}
int main() {
    vector<int>p = {4, 2, 3, 4, 5};
    auto [minCost, s] = matrixChain(p);
    cout << "Min. number of scalar multiplications: " << minCost << endl;
    cout << "Optimal parenthesization: ";
    print(s, 1, p.size() - 1);
    cout << endl;
    return 0;
}
