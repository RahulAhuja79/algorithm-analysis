Cycle Detection
-
Aim:
Detect whether a cycle exists in an undirected graph using Depth First Search (DFS).

Algorithm:

    DFS(node, parent)

    Mark node as visited

    FOR each neighbor of node:
        IF neighbor is not visited:
            IF DFS(neighbor, node) returns true:
                RETURN true

        ELSE IF neighbor != parent:
            RETURN true

    RETURN false

Complexity:

Best: O(V + E)

Average: O(V + E)

Worst: O(V + E)

Space: O(V)

Use case:

Detect loops in networks

Graph validation

Deadlock detection

Dijkstra Algorithm
-
Aim:
Find the shortest path from a source node to all other nodes in a weighted graph.

Algorithm:

    Initialize dist[] = INF for all nodes
    dist[src] = 0

    Repeat V-1 times:
        pick unvisited node with minimum distance

        FOR each neighbor:
            IF shorter path is found:
                update distance
                update parent

Complexity:

Best: O(n²)

Average: O(n²)

Worst: O(n²)

Space: O(n)

Can be optimized to O((V + E) log V) using a priority queue.

Use case:

GPS navigation systems

Network routing

Shortest path problems
