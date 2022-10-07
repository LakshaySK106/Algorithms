#include<iostream>
#include<vector>
#include<list>

using namespace std;

// class to represent graph data structure
class Graph
{
	int V;                  // number of vertices
	vector<list<int>> adj;  // adjacency list
public:
	Graph(int V);           // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints BFS traversal from a given source s
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);    // Add w to v’s list.
}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	vector<bool> visited;
	visited.resize(V,false);

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

int main()
{
	Graph g(4);             // creating a graph with 4 nodes
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout<<"BFS for the given graph starting with vertex 1:\n";
	g.BFS(1);

	return 0;
}
