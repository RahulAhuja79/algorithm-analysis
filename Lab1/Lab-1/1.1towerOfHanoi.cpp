#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Tower of Hanoi (only counting recursive calls)
void move(int n, char from, char temp, char to) {
    if (n == 0)
        return;

    move(n - 1, from, to, temp);
    // move happens here but not printed
    move(n - 1, temp, from, to);
}

int main() {

    int repeat = 100;

    cout << "Rings\tAverageTime(ns)\n";

    for (int n = 3; n <= 15; n++) {

        long long total = 0;

        for (int i = 0; i < repeat; i++) {

            auto startTime = high_resolution_clock::now();
            move(n, 'A', 'B', 'C');
            auto endTime = high_resolution_clock::now();

            auto timeTaken = duration_cast<nanoseconds>(endTime - startTime);
            total += timeTaken.count();
        }

        double avg = (double)total / repeat;
        cout << n << "\t" << avg << endl;
    }

    return 0;
}
