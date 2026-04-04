#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {

        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }

    swap(arr[low], arr[j]);
    return j;
}

int kthSmallest(int arr[], int low, int high, int k) {

    if (low <= high) {

        int p = partition(arr, low, high);

        if (p == k - 1)
            return arr[p];

        else if (p > k - 1)
            return kthSmallest(arr, low, p - 1, k);

        else
            return kthSmallest(arr, p + 1, high, k);
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cout << "Enter kth position: ";
    cin >> k;

    cout << k << "th smallest element is: "
         << kthSmallest(arr, 0, n - 1, k);

    return 0;
}