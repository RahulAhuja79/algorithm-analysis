#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Linear search function
void linearSearch(int arr[], int n) {
    int key = rand();   // random key to search

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            break;      // stop when found
        }
    }
}

// Function to calculate average execution time
int measureTime(int arr[], int n) {
    int total = 0;

    for (int run = 0; run < 100; run++) {

        // Fill array with random numbers
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        auto startTime = system_clock::now();
        linearSearch(arr, n);
        auto endTime = system_clock::now();

        total += duration_cast<nanoseconds>(endTime - startTime).count();
    }

    return total / 100;   // average time
}

int main() {
    int arr[10000];

    // Test array sizes from 1000 to 9000
    for (int size = 1000; size < 10000; size += 1000) {
        int avgTime = measureTime(arr, size);
        cout << size << " - "<< avgTime << " ns" << endl;
    }

    return 0;
}
