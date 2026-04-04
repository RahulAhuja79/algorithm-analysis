#include <iostream>
#include <vector>
using namespace std;

// addition
vector<vector<int>> add(vector<vector<int>> X, vector<vector<int>> Y, int n) {
    vector<vector<int>> res(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            res[i][j] = X[i][j] + Y[i][j];
    return res;
}

// subtraction
vector<vector<int>> sub(vector<vector<int>> X, vector<vector<int>> Y, int n) {
    vector<vector<int>> res(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            res[i][j] = X[i][j] - Y[i][j];
    return res;
}

// strassen
vector<vector<int>> solve(vector<vector<int>> A, vector<vector<int>> B, int n) {

    vector<vector<int>> ans(n, vector<int>(n));

    if(n == 1) {
        ans[0][0] = A[0][0] * B[0][0];
        return ans;
    }

    int half = n/2;

    vector<vector<int>> a11(half, vector<int>(half)), a12(half, vector<int>(half));
    vector<vector<int>> a21(half, vector<int>(half)), a22(half, vector<int>(half));

    vector<vector<int>> b11(half, vector<int>(half)), b12(half, vector<int>(half));
    vector<vector<int>> b21(half, vector<int>(half)), b22(half, vector<int>(half));

    // split matrices
    for(int i=0;i<half;i++){
        for(int j=0;j<half;j++){
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j+half];
            a21[i][j] = A[i+half][j];
            a22[i][j] = A[i+half][j+half];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j+half];
            b21[i][j] = B[i+half][j];
            b22[i][j] = B[i+half][j+half];
        }
    }

    // 7 multiplications
    vector<vector<int>> p1 = solve(add(a11,a22,half), add(b11,b22,half), half);
    vector<vector<int>> p2 = solve(add(a21,a22,half), b11, half);
    vector<vector<int>> p3 = solve(a11, sub(b12,b22,half), half);
    vector<vector<int>> p4 = solve(a22, sub(b21,b11,half), half);
    vector<vector<int>> p5 = solve(add(a11,a12,half), b22, half);
    vector<vector<int>> p6 = solve(sub(a21,a11,half), add(b11,b12,half), half);
    vector<vector<int>> p7 = solve(sub(a12,a22,half), add(b21,b22,half), half);

    vector<vector<int>> c11 = add(sub(add(p1,p4,half),p5,half),p7,half);
    vector<vector<int>> c12 = add(p3,p5,half);
    vector<vector<int>> c21 = add(p2,p4,half);
    vector<vector<int>> c22 = add(sub(add(p1,p3,half),p2,half),p6,half);

    // combine
    for(int i=0;i<half;i++){
        for(int j=0;j<half;j++){
            ans[i][j] = c11[i][j];
            ans[i][j+half] = c12[i][j];
            ans[i+half][j] = c21[i][j];
            ans[i+half][j+half] = c22[i][j];
        }
    }

    return ans;
}

int main() {

    int n = 2;

    // 🔹 changed values
    vector<vector<int>> A = {{2,1},{4,3}};
    vector<vector<int>> B = {{1,5},{2,6}};

    vector<vector<int>> result = solve(A, B, n);

    cout << "Result:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}