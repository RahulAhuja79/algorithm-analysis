Activity Selection
-
Aim:
Select the maximum number of activities that do not overlap.

Algorithm:

    Sort activities based on finish time

    Select first activity

    FOR each next activity:
        IF start time >= finish time of last selected activity:
            select activity

Complexity:

Best: O(n log n)

Average: O(n log n)

Worst: O(n log n)

Space: O(1)

Use case:

Scheduling problems

Resource allocation

Event planning

Dijkstra Algorithm
-
Aim:
Find the shortest path from a source node to all other nodes in a graph.

Algorithm:

    Initialize distance of all vertices

    WHILE unvisited vertices exist:
        pick vertex with minimum distance

        update distance of its neighboring vertices

Complexity:

Best: O(n²)

Average: O(n²)

Worst: O(n²)

Space: O(n)

Use case:

Routing

Navigation systems

Network optimization
