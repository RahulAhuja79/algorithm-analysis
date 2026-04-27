Kruskal Algorithm
-
Aim:
Find Minimum Spanning Tree (MST) using a greedy approach.

Algorithm:

    Sort all edges based on weight (small to large)

    FOR each edge in sorted order:
        IF adding edge does NOT create a cycle:
            include the edge in MST

Complexity:

Best: O(E log E)

Average: O(E log E)

Worst: O(E log E)

Space: O(V)

Use case:

Network design

Road planning

Cable layout

Prim Algorithm
-
Aim:
Find Minimum Spanning Tree starting from a selected vertex.

Algorithm:

    Start from any vertex

    REPEAT:
        pick the minimum weight edge
        that connects tree to a new vertex

Complexity:

Best: O(n²)

Average: O(n²)

Worst: O(n²)

Space: O(n)

Use case:

Network design

Infrastructure planning

Graph optimization
