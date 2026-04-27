Merge Sort
-
Aim:
Sort an array efficiently using divide-and-conquer by splitting it into halves, sorting them, and then merging them.

Algorithm:

    MergeSort(arr, start, end)

     IF start < end:
       mid = start + (end - start) / 2

    MergeSort(arr, start, mid)
    MergeSort(arr, mid + 1, end)

    Merge(arr, start, mid, end)


      Merge(arr, start, mid, end)

        Create left[] and right[] arrays
        Copy elements into left[] and right[]

        i = 0, j = 0, k = start

      WHILE i < size(left) AND j < size(right):
    IF left[i] <= right[j]:
        arr[k] = left[i]
        i++
    ELSE:
        arr[k] = right[j]
        j++
    k++

     Copy remaining elements of left[]
    Copy remaining elements of right[]

Complexity:

Best: O(n log n)

Average: O(n log n)

Worst: O(n log n)

Space: O(n)

Merge Sort always takes O(n log n) time. Extra space is needed for temporary arrays.

Use case:

Sorting large datasets

External sorting (files, databases)

When stable sorting is needed

Used in divide-and-conquer problems

Quick Sort
-
Aim:
Sort an array by choosing a pivot and arranging smaller elements before it and larger elements after it.

Algorithm:

     QuickSort(arr, low, high)

     IF low < high:
    pivotIndex = Partition(arr, low, high)

    QuickSort(arr, low, pivotIndex - 1)
    QuickSort(arr, pivotIndex + 1, high)


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
        i++
        j--

     swap(arr[low], arr[j])
     RETURN j

Complexity:

Best: O(n log n)

Average: O(n log n)

Worst: O(n²)

Space: O(log n) (average), O(n) (worst)

Quick Sort is very fast in practice but can become slow if the pivot is badly chosen (like in a sorted array).

Use case:

Fast in-memory sorting

When low memory usage is important

Used in optimized library sorting

Works well for random data
