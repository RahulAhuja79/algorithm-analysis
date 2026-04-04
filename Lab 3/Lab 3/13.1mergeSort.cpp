#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;


void combineParts(vector<int> &data, int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    vector<int> firstHalf(leftSize), secondHalf(rightSize);

  
    for (int x = 0; x < leftSize; ++x)
        firstHalf[x] = data[left + x];

    for (int y = 0; y < rightSize; ++y)
        secondHalf[y] = data[middle + 1 + y];

    int p = 0, q = 0;
    int index = left;

    
    while (p < leftSize && q < rightSize) {
        if (firstHalf[p] < secondHalf[q]) {
            data[index] = firstHalf[p];
            p++;
        } else {
            data[index] = secondHalf[q];
            q++;
        }
        index++;
    }

    // remaining elements
    while (p < leftSize) {
        data[index++] = firstHalf[p++];
    }

    while (q < rightSize) {
        data[index++] = secondHalf[q++];
    }
}

// Recursive merge sort
void applyMergeSort(vector<int> &data, int low, int high) {
    if (low >= high) return;

    int center = low + (high - low) / 2;

    applyMergeSort(data, low, center);
    applyMergeSort(data, center + 1, high);

    combineParts(data, low, center, high);
}


long long computeAverageTime(vector<int> base, int runs) {
    long long timeSum = 0;

    for (int i = 0; i < runs; ++i) {
        vector<int> temp = base;

        auto t1 = high_resolution_clock::now();
        applyMergeSort(temp, 0, temp.size() - 1);
        auto t2 = high_resolution_clock::now();

        timeSum += duration_cast<milliseconds>(t2 - t1).count();
    }

    return timeSum / runs;
}

int main() {

    int runs = 100;
    cout << "InputSize\tTime(ms)\n";

    for (int size = 1000; size <= 10000; size += 1000) {

        vector<int> values(size);

       
        for (int i = 0; i < size; ++i) {
            values[i] = rand();
        }

        long long avgTime = computeAverageTime(values, runs);

        cout << size << "\t\t" << avgTime << endl;
    }

    return 0;
}