#include <iostream>
#include<map>
#include<list>

using namespace std;

// class to represent graph data structure
class Graph {
public:
	map<int, bool> visited;         // visited array
	map<int, list<int> > adj;       // adjacency list

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints DFS traversal from a given source s
	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

int main()
{
	Graph g;                // creating a graph
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "DFS for the above graph starting from node 2:\n";
	g.DFS(2);

	return 0;
}