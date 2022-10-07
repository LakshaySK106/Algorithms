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


## Breadth First Search (BFS)

Breadth-First Traversal (or Search) for a graph is similar to Breadth-First Traversal of a tree (See method 2 of this post). 
The only catch here is, that, unlike trees, graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we divide the vertices into two categories:
- Visited and
- Not visited.

A boolean visited array is used to mark the visited vertices. For simplicity, it is assumed that all vertices are reachable from the starting vertex. BFS uses a queue data structure for traversal.

**Example:**

In the following graph, we start traversal from vertex 2.


When we come to vertex 0, we look for all adjacent vertices of it. 
- 2 is also an adjacent vertex of 0. 
- If we don’t mark visited vertices, then 2 will be processed again and it will become a non-terminating process.

There can be multiple BFS traversals for a graph. Different BFS traversals for the above graph:
2, 3, 0, 1
2, 0, 3, 1

**Steps for BFS Algorithm:**
- Declare a queue and insert the starting vertex.
- Initialize a visited array and mark the starting vertex as visited.
- Follow the below process till the queue becomes empty:
- Remove the first vertex of the queue.
- Mark that vertex as visited.
- Insert all the unvisited neighbours of the vertex into the queue.

**Time Complexity:** O(V+E), where V is the number of nodes and E is the number of edges.</br>
**Auxiliary Space:** O(V)

**Diagram Reference:** geeksforgeeks