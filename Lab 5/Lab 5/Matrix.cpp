#include <iostream>
using namespace std;

#define MAX 100

// matrix addition
void add(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

// recursive multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int n) {

    if (n == 1) {
        R[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;

    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];

    int temp1[MAX][MAX], temp2[MAX][MAX];

    // splitting matrices
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // C11
    multiplyMatrix(A11, B11, temp1, half);
    multiplyMatrix(A12, B21, temp2, half);
    add(temp1, temp2, C11, half);

    // C12
    multiplyMatrix(A11, B12, temp1, half);
    multiplyMatrix(A12, B22, temp2, half);
    add(temp1, temp2, C12, half);

    // C21
    multiplyMatrix(A21, B11, temp1, half);
    multiplyMatrix(A22, B21, temp2, half);
    add(temp1, temp2, C21, half);

    // C22
    multiplyMatrix(A21, B12, temp1, half);
    multiplyMatrix(A22, B22, temp2, half);
    add(temp1, temp2, C22, half);

    // combining result
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            R[i][j] = C11[i][j];
            R[i][j + half] = C12[i][j];
            R[i + half][j] = C21[i][j];
            R[i + half][j + half] = C22[i][j];
        }
    }
}

int main() {

    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    int n;

    cout << "Enter size: ";
    cin >> n;

    // input matrix A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // input matrix B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    multiplyMatrix(A, B, R, n);

    cout << "Result:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
}