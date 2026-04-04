#include <iostream>
using namespace std;

// Function to find minimum and maximum using divide & conquer
void findMinMax(int nums[], int left, int right, int &minVal, int &maxVal) {

    if (left == right) {
        minVal = nums[left];
        maxVal = nums[left];
        return;
    }

    if (right == left + 1) {
        if (nums[left] < nums[right]) {
            minVal = nums[left];
            maxVal = nums[right];
        } else {
            minVal = nums[right];
            maxVal = nums[left];
        }
        return;
    }

    int midIndex = (left + right) / 2;

    int leftMin, leftMax;
    int rightMin, rightMax;

    findMinMax(nums, left, midIndex, leftMin, leftMax);
    findMinMax(nums, midIndex + 1, right, rightMin, rightMax);

    minVal = (leftMin < rightMin) ? leftMin : rightMin;
    maxVal = (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
    int size;

    cout << "Enter number of elements: ";
    cin >> size;

    int *values = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> values[i];
    }

    int minimum, maximum;

    findMinMax(values, 0, size - 1, minimum, maximum);

    cout << minimum << " " << maximum << endl;

    return 0;
}