All Pairs Shortest Path
-
Aim:
Find the shortest paths between every pair of vertices in a graph using dynamic programming.

Algorithm:

    APSP(dist, next)

    FOR k = 0 to n - 1:
        FOR i = 0 to n - 1:
            FOR j = 0 to n - 1:

                IF dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    next[i][j] = next[i][k]

Complexity:

Best: O(n³)

Average: O(n³)

Worst: O(n³)

Space: O(n²)

Works for both directed and undirected graphs. Can handle negative weights (but not negative cycles).

Use case:

Network routing algorithms

Finding shortest paths between all cities

Graph analysis problems
