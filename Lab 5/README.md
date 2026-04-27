Convex Hull
-
Aim:
Find the smallest convex shape  that contains all given points.

Algorithm:

    Divide points into left half and right half

    Recursively find convex hull of both halves

    Merge the two hulls:
        Find upper tangent
        Find lower tangent

    Combine both hulls to form final hull

Complexity:

Best: O(n log n)

Average: O(n log n)

Worst: O(n log n)

Space: O(n)

Use case:

Computer graphics

GIS systems

Collision detection

Knapsack Problem
-
Aim:
Maximize profit by selecting items with given weight and profit (fraction allowed).

Algorithm:

    Sort items based on:
        profit/weight OR profit OR weight

    FOR each item:
        IF weight <= capacity:
            take whole item
        ELSE:
            take fraction of item
            break

Complexity:

Best: O(n log n)

Average: O(n log n)

Worst: O(n log n)

Space: O(1)

Greedy approach.

Use case:

Resource allocation

Budget optimization

Cargo loading

Matrix Multiplication
-
Aim:
Multiply two matrices using divide and conquer method.

Algorithm:

    Divide matrices into 4 submatrices

    Recursively compute:

        C11 = A11B11 + A12B21
        C12 = A11B12 + A12B22
        C21 = A21B11 + A22B21
        C22 = A21B12 + A22B22

    Combine all results to get final matrix

Complexity:

Best: O(n³)

Average: O(n³)

Worst: O(n³)

Space: O(n²)

Use case:

Scientific computing

Graphics transformations

Linear algebra

Strassen Algorithm
-
Aim:
Multiply matrices faster than normal method using divide and conquer.

Algorithm:

    Divide matrices into submatrices

    Compute 7 products:
        M1, M2, M3, M4, M5, M6, M7

    Use these to calculate result matrix C

Complexity:

Best: O(n^2.81)

Average: O(n^2.81)

Worst: O(n^2.81)

Space: O(n²)

Use case:

Large matrix multiplication

Scientific simulations

Performance-critical systems
