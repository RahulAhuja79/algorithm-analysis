#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

struct Activity {
    int start;
    int end;
};

// finish time ke basis pe sort
bool sortByEnd(Activity a, Activity b) {
    return a.end < b.end;
}

void selectActivities(Activity arr[], int n) {

    sort(arr, arr + n, sortByEnd);

    cout << "\nFor n = " << n << endl;
    cout << "Start\tEnd\n";

    // first activity always select hoti hai
    cout << arr[0].start << "\t" << arr[0].end << endl;

    int last = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= arr[last].end) {
            cout << arr[i].start << "\t" << arr[i].end << endl;
            last = i;
        }
    }
}

int main() {

    for (int n = 10; n <= 50; n += 10) {

        Activity arr[MAX];

        // random values (thoda realistic range)
        for (int i = 0; i < n; i++) {
            arr[i].start = rand() % 50;
            arr[i].end = arr[i].start + (rand() % 10 + 1); // ensure end > start
        }

        selectActivities(arr, n);
    }

    return 0;
}