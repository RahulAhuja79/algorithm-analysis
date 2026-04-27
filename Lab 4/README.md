K-th Smallest Element
-
Aim:
Find the k-th smallest element in an unsorted array using partition logic (Quick Select).

Algorithm:

    Partition(arr, low, high)

    pivot = arr[low]
    i = low + 1
    j = high

    WHILE i <= j:
        WHILE arr[i] < pivot:
            i++

        WHILE arr[j] > pivot:
            j--

        IF i < j:
            swap(arr[i], arr[j])

    swap(arr[low], arr[j])
    RETURN j


    Smallest(arr, low, high, k)

    j = Partition(arr, low, high)

    IF j + 1 == k:
        RETURN arr[j]

    ELSE IF j + 1 < k:
        RETURN Smallest(right subarray)

    ELSE:
        RETURN Smallest(left subarray)

Complexity:

Best: O(n)

Average: O(n)

Worst: O(n²)

Space: O(1)

Based on Quick Sort partitioning.

Use case:

Order statistics

Finding median

Selection problems

Min-Max Problem
-
Aim:
Find the minimum and maximum elements in an array efficiently using divide and conquer.

Algorithm:

    MinMax(arr, low, high)

    IF low == high:
        min = max = arr[low]

    ELSE IF only two elements:
        compare and assign min and max

    ELSE:
        mid = (low + high) / 2

        (min1, max1) = MinMax(left)
        (min2, max2) = MinMax(right)

        min = min(min1, min2)
        max = max(max1, max2)

Complexity:

Best: O(n)

Average: O(n)

Worst: O(n)

Space: O(log n)

Reduces comparisons compared to brute force.

Use case:

Finding range of values

Data preprocessing

Statistical computation
