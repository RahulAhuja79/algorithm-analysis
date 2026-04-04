#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to place pivot at correct position
int arrangePivot(vector<int> &data, int start, int end) {
    int pivotValue = data[start];
    int leftPtr = start + 1;
    int rightPtr = end;

    while (true) {

        while (leftPtr <= rightPtr && data[leftPtr] < pivotValue)
            leftPtr++;

        while (leftPtr <= rightPtr && data[rightPtr] > pivotValue)
            rightPtr--;

        if (leftPtr >= rightPtr)
            break;

        swap(data[leftPtr], data[rightPtr]);
        leftPtr++;
        rightPtr--;
    }

    swap(data[start], data[rightPtr]);
    return rightPtr;
}


void runQuickSort(vector<int> &data, int begin, int finish) {
    if (begin >= finish) return;

    int pivotIndex = arrangePivot(data, begin, finish);

    runQuickSort(data, begin, pivotIndex - 1);
    runQuickSort(data, pivotIndex + 1, finish);
}


long long calculateAvgTime(vector<int> baseArray, int runs) {
    long long total = 0;

    for (int count = 0; count < runs; ++count) {
        vector<int> temp = baseArray;

        auto tStart = high_resolution_clock::now();
        runQuickSort(temp, 0, temp.size() - 1);
        auto tEnd = high_resolution_clock::now();

        total += duration_cast<milliseconds>(tEnd - tStart).count();
    }

    return total / runs;
}

int main() {

    int runs = 100;
    cout << "InputSize\tTime(ms)\n";

    for (int size = 1000; size <= 10000; size += 1000) {

        vector<int> values(size);

     
        for (int i = 0; i < size; ++i) {
            values[i] = rand();
        }

        long long avgTime = calculateAvgTime(values, runs);

        cout << size << "\t\t" << avgTime << endl;
    }

    return 0;
}