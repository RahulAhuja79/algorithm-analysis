#include <iostream>
using namespace std;

// Function to find missing number using LSB method
int findMissing(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] & 1) == (arr[i + 1] & 1)) {
            return (arr[i] + arr[i + 1]) / 2;  // Missing number
        }
    }
    return -1;  // If no missing number found
}

int main() {
    int arr[20];

    cout << "Enter 20 numbers (consecutive, one missing):" << endl;
    for (int i = 0; i < 20; i++) {
        cin >> arr[i];
    }

    int missing = findMissing(arr, 20);
    cout << "Missing number: " << missing << endl;

    return 0;
}
