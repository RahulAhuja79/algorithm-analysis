#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;


void performInsertionSort(vector<int> &numbers) {
    int currentValue, prevIndex;
    int size = numbers.size();

    for (int i = 1; i < size; i++) {
        currentValue = numbers[i];
        prevIndex = i - 1;

        while (prevIndex >= 0 && numbers[prevIndex] > currentValue) {
            numbers[prevIndex + 1] = numbers[prevIndex];
            prevIndex--;
        }

        numbers[prevIndex + 1] = currentValue;
    }
}

int main() {

    int testRuns = 100;

    cout << "InputSize\tBest case(ms)\tWorst case(ms)\n";

    for (int size = 1000; size <= 10000; size += 1000) {

        // Creating worst-case input (descending order)
        vector<int> descendingList(size);
        for (int i = 0; i < size; i++) {
            descendingList[i] = size - i;
        }

        // Creating best-case input (already sorted)
        vector<int> ascendingList(size);
        for (int i = 0; i < size; i++) {
            ascendingList[i] = i;
        }

        long long bestCaseTime = 0;
        long long worstCaseTime = 0;

        // Measuring best case
        for (int run = 0; run < testRuns; run++) {
            vector<int> testData = ascendingList;

            auto startTime = high_resolution_clock::now();
            performInsertionSort(testData);
            auto endTime = high_resolution_clock::now();

            bestCaseTime += duration_cast<milliseconds>(endTime - startTime).count();
        }

        // Measuring worst case
        for (int run = 0; run < testRuns; run++) {
            vector<int> testData = descendingList;

            auto startTime = high_resolution_clock::now();
            performInsertionSort(testData);
            auto endTime = high_resolution_clock::now();

            worstCaseTime += duration_cast<milliseconds>(endTime - startTime).count();
        }

        cout << size << "\t\t"
             << bestCaseTime / testRuns << "\t\t"
             << worstCaseTime / testRuns << endl;
    }

    return 0;
}