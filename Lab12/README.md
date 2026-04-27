Traveling Salesperson Problem
-
Aim:
Efficiently find the minimum cost to visit all cities exactly once and return to the starting city using Dynamic Programming with Bitmasking.

Algorithm:

    TSP(pos, mask)

    IF mask == (1 << n) - 1:
        RETURN dist[pos][0]

    IF dp[pos][mask] != -1:
        RETURN dp[pos][mask]

    ans = INF

    FOR each city from 0 to n - 1:
        IF city is not visited in mask:
            newAns = dist[pos][city] + TSP(city, mask | (1 << city))
            ans = min(ans, newAns)

    RETURN dp[pos][mask] = ans

Complexity:

Best: O(n² · 2ⁿ)

Average: O(n² · 2ⁿ)

Worst: O(n² · 2ⁿ)

Space: O(n · 2ⁿ)


Use case:

Route optimization (delivery, logistics)


Circuit design (minimizing wiring cost)

Genome sequencing (bioinformatics)
