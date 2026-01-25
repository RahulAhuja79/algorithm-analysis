#include <iostream>
using namespace std;

long long horner(int coeff[], int n, int x, int i) {
    if (i == n)
        return coeff[i];
    return coeff[i] + x * horner(coeff, n, x, i + 1);
}

int main() {
    int n = 4;
    int coeff[] = {1, 2, 3, 4, 5};
    int x = 2;

    cout << "Polynomial value: " << horner(coeff, n, x, 0);

    return 0;
}