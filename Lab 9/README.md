Multistage Graph (Stage Identification)
-
Aim:
Determine the number of stages in a graph by grouping nodes based on reachability.

Algorithm:

    Start with stage 0 containing the source node

    WHILE there are new reachable nodes:
        add all reachable nodes as the next stage

Complexity:

Best: O(n²)

Average: O(n²)

Worst: O(n²)

Space: O(n)

Use case:

Breaking problems into stages

Pipeline processing

Graph layering
