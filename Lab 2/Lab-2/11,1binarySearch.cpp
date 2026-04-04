#include <iostream>
#include<chrono>
#include<cstdlib>
#include<vector>
using namespace std;
using namespace chrono;

int binarySearch(vector<int>& array, int low , int high , int target){
if (low>high) return -1;
int mid=low+(high-low)/2;
if (mid==target) return mid;
else if(mid>target) return binarySearch(array, low,mid-1, target);
else return binarySearch(array,mid+1,high, target);
}
int main() {
    int repeat = 100;
int target;
    cout << "InputSize\tBubbleSort(ns)\n";

    for (int size = 1000; size <= 7000; size += 1000) {

        // Fill original array with random numbers
        vector<int> orig(size);
        for (int i = 0; i < size; i++)
            orig[i] = rand() % 100000;

         long totalTime = 0;

        for (int run = 0; run < repeat; run++) {
            vector<int> array = orig;
 target=rand();
            auto startTime = high_resolution_clock::now();
            binarySearch(array, 0, size ,target);
            auto endTime = high_resolution_clock::now();

            totalTime += duration_cast<nanoseconds>(endTime - startTime).count();
        }

        cout << size << "\t\t" << totalTime / repeat << endl;
    }

    return 0;
}