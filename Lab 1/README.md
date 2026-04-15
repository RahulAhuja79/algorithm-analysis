# algorithm-analysis
1. Fast Power of X^n (Recursive)

Aim
-
To calculate the value of a number raised to a power in an efficient way using recursion.

Algorithm
-
      int Power(int base, int exp) {
    if (exp == 0)
        return 1;

    int half = power(base, exp / 2);

    if (exp % 2 == 0)
        return half * half;
    else
        return base * half * half;
    }

Time Complexity
-
At each recursive call, the exponent becomes half.

Time Complexity: O(log n)

Space Complexity: O(log n)

Use Case
-
Used in cryptography,

competitive programming for large powers.

 ------------------------------------------------------------------------------------------
2. Permutations of a String
    
Aim
-
To print all possible arrangements of characters in a string.

Algorithm
-
          void generatePerm(string &str, int start, int end) {
    if (start == end) {
         print str
        return;
    }

    for (int pos = start; pos <= end; pos++) {
        swap(str[start], str[pos]);
        generatePerm(str, start + 1, end);
        swap(str[start], str[pos]);  
    }
    }

Time Complexity
-
Time: O(n × n!)
Space: O(n) (due to recursion)

Use Case
-
Anagram problems,

Brute force searching,

Generating possible passwords

------------------------------------------------------------------------------------------

3. Horner’s Method
   
Aim
-
To calculate the value of a polynomial efficiently using recursion.

Algorithm
-
    long long evaluatePoly(const vector<int>& terms, int value, int pos) {

    if (pos == terms.size() - 1)
        return terms[pos];

    return terms[pos] + value * evaluatePoly(terms, value, pos + 1);
   }

Time Complexity
-
Time: O(n)
Space: O(n) (recursive)

Use Case
-
Polynomial calculations,

Numerical computation,

Used in compilers for expression evaluation

--------------------------------------------------------------------------------------------

4. Tower of Hanoi
   
Aim
-
To solve the Tower of Hanoi problem using recursion and understand its time growth.

Algorithm
-
     TOH(n, start, free, end)
        If n == 1
       Print "Move disk from start to end"
       Return
           TOH(n-1, start, end, free)
         Print "Move disk from start to end"
          TOH(n-1, free, start, end)


Time Complexity
-
Time: O(2^n)
Space: O(n)

Use Case
-
Classic recursion example

Understanding divide and conquer

--------------------------------------------------------------------------------------------
5. Bubble Sort
   
Aim
-
To arrange elements of an array in ascending order.

Algorithm
-
    void bubble(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
     }
 }


Time Complexity
-
Time: O(n²)
Space: O(1)

Use Case
-
Useful for learning sorting basics

Suitable only for small data


-----------------------------------------------------------------------------------------
6.  Selection Sort

Aim
-
To arrange elements of an array in ascending order.

Algorithm
-
       void selection(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        swap(arr[i], arr[min]);
    }
    }

Time Complexity
-
Time: O(n²)
Space: O(1)

Use Case
-
Useful for learning sorting basics

Suitable only for small data

--------------------------------------------------------------------------------------
7. Finding Missing Number Using Bit Logic

Aim
-
To find a missing number in a sequence using bitwise comparison.

Algorithm
-
    int missing(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] & 1) == (arr[i + 1] & 1)) {
            return (arr[i] + arr[i + 1]) / 2;
        }
    }

    return -1;
   }


Time Complexity
-
Time: O(n)
Space: O(1)

Use Case
-
Bitwise logic problems

Detecting missing element in sequence

---------------------------------------------------------------------------------------

8. Counting Tips Until Velocity is Less Than 1

Aim
-
To count how many times a value reduces until it becomes less than 1.

Algorithm
-
     int tips(double v) {

    if (v < 1.0)
        return 0;

    return 1 + tips(v - 0.425);
     }


Time Complexity
-
Time: O(v)
Space: O(v)

Use Case
-
Understanding simple linear recursion

Studying recursion depth

------------------------------------------------------------------------------------

9. Truth Table Generation

Aim
-
To generate all combinations of n boolean variables.

Algorithm
-
    bool a[50];

    void truth(int k, int n) {

    if (k > n) {
        // print a
        return;
    }

    a[k] = true;
    truth(k + 1, n);

    a[k] = false;
    truth(k + 1, n);
    }


Time Complexity
-
Time: O(2^n)

Space: O(n)

Use Case
-
Digital circuits

Boolean algebra

Logic design

-------------------------------------------------------------------------------------------

10. Linear Search
    
Aim
-
To find a particular element in an array using sequential checking.

Algorithm
-
    void sequentialSearch(int data[], int size) {

    void search(int arr[], int n) {

    int x = rand();

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            break;
        }
    }
      }


Time Complexity
-
Best Case: O(1) (element found at start)

Average Case: O(n)

Worst Case: O(n) (element at end or not present)

Space Complexity: O(1)

Use Case
-
Small datasets

Unsorted arrays

When sorting is not required

---------------------------------------------------------------------------------------------------------------------
