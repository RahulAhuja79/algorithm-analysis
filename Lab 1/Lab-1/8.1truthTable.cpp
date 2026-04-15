#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool arr[20];   // Array to store True/False values

// Recursive Truth Table Generator
void truth(int i, int n)
{
    if (i > n)
    {
        // Normally: print arr[1..n]
        // Printing skipped to measure time properly
        return;
    }

    arr[i] = true;     // Set True
    truth(i + 1, n);   // Recursive call

    arr[i] = false;    // Set False
    truth(i + 1, n);   // Recursive call
}

int main()
{
    int repeat = 100;

    cout << "Inputs(n)\tAverageTime(us)\n";

    // Change input size from 2 to 15
    for (int n = 2; n <= 15; n++)
    {
        long long total = 0;

        // Run 100 times
        for (int j = 0; j < repeat; j++)
        {
            auto startTime = high_resolution_clock::now();
            truth(1, n);
            auto endTime = high_resolution_clock::now();

            total += duration_cast<microseconds>(endTime - startTime).count();
        }

        double avg = (double)total / repeat;
        cout << n << "\t\t" << avg << endl;
    }

    return 0;
}
