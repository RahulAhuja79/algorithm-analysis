#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

// Bubble Sort function
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int repeat = 100;

    cout << "InputSize\tBubbleSort(ms)\n";

    for (int size = 1000; size <= 7000; size += 1000) {

        // Fill original array with random numbers
        vector<int> orig(size);
        for (int i = 0; i < size; i++)
            orig[i] = rand() % 100000;

        long long totalTime = 0;

        for (int run = 0; run < repeat; run++) {
            vector<int> arr = orig;

            auto startTime = high_resolution_clock::now();
            bubbleSort(arr);
            auto endTime = high_resolution_clock::now();

            totalTime += duration_cast<milliseconds>(endTime - startTime).count();
        }

        cout << size << "\t\t" << totalTime / repeat << endl;
    }

    return 0;
}
