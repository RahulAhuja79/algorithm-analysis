#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function to generate permutations
void permute(string &str, int left, int right) {
    if (left == right) {
        // Only generate permutations, do not print (printing changes timing)
        return;
    }

    for (int i = left; i <= right; i++) {
        swap(str[left], str[i]);
        permute(str, left + 1, right);
        swap(str[left], str[i]); // restore original order
    }
}

int main() {

    int repeat = 100;

    cout << "InputSize\tAverageTime\n";

    for (int n = 3; n <= 10; n++) {

        string str = "";
        for (int i = 0; i < n; i++)
            str += char('A' + i);   // ABC, ABCD, ...

        long long total = 0;

        for (int i = 0; i < repeat; i++) {

            auto startTime = high_resolution_clock::now();
            permute(str, 0, n - 1);
            auto endTime = high_resolution_clock::now();

            auto timeTaken = duration_cast<microseconds>(endTime - startTime);
            total += timeTaken.count();
        }

        double average = (double)total / repeat;
        cout << n << "\t\t" << average << endl;
    }

    return 0;
}
