Binary Search
-
Aim:
Find a target value in a sorted array quickly by checking the middle element and reducing the search area again and again.

Algorithm:

    BinarySearch(arr, low, high, target)

     IF low > high:
    RETURN -1

     mid = low + (high - low) / 2

    IF arr[mid] == target:
    RETURN mid

    ELSE IF arr[mid] > target:
    RETURN BinarySearch(arr, low, mid-1, target)

    ELSE:
       RETURN BinarySearch(arr, mid+1, high, target)

Complexity:

Best: O(1)

Average: O(log n)

Worst: O(log n)

Space: O(log n) (due to recursion)

Iterative method uses O(1) space

Use case:

Searching words in a sorted dictionary

Finding items in a sorted product list

Finding a bug version (like binary search in debugging)

Insertion Sort
-
Aim:
Sort an array step by step by placing each element in its correct position.

Algorithm:

    InsertionSort(arr, n):

       FOR i = 1 TO n-1:
        key = arr[i]
         j = i - 1

       WHILE j >= 0 AND arr[j] > key:
          arr[j+1] = arr[j]
        j = j - 1

    arr[j+1] = key

Complexity:

Best: O(n) (already sorted)

Average: O(n²)

Worst: O(n²) (reverse order)

Space: O(1)

Use case:

Sorting playing cards in hand

Adding new elements into a sorted list

Used in bigger algorithms for sorting small parts
