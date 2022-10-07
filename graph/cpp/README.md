Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. The only catch here is, that, unlike trees, graphs may contain cycles (a node may be visited twice). To avoid processing a node more than once, use a boolean visited array. A graph can have more than one DFS traversal.

Example: 

Input: n = 4, e = 6 
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3 
Output: DFS from vertex 1 : 1 2 0 3 
Explanation: 
DFS Diagram:


Steps of the Algorithms:

Create a recursive function that takes the index of the node and a visited array.
Mark the current node as visited and print the node.
Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.

Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Auxiliary Space: O(V), since an extra visited array of size V is required.