## Depth First Search (DFS)

Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. The only catch here is, that, unlike trees, graphs may contain cycles (a node may be visited twice). To avoid processing a node more than once, use a boolean visited array. A graph can have more than one DFS traversal.

**Example:** 

Input: n = 4, e = 6 
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3 
Output: DFS from vertex 1 : 1 2 0 3
DFS Diagram:

![ezgif com-gif-maker61](https://user-images.githubusercontent.com/53170095/194474745-3a1bd15e-4123-4b01-a415-eec21095a822.gif)

**Steps of the Algorithms:**

- Create a recursive function that takes the index of the node and a visited array.
- Mark the current node as visited and print the node.
- Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.

**Time complexity:** O(V + E), where V is the number of vertices and E is the number of edges in the graph.</br>
**Auxiliary Space:** O(V), since an extra visited array of size V is required.</br></br>

**Diagram Reference:** geeksforgeeks
