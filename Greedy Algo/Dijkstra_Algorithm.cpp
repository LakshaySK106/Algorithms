#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<int> Dijkstra(int nodes, vector<vector<int>> adj[], int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> result(nodes, INT32_MAX);

    result[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto &iter : adj[node])
        {
            int edgeWeight = iter[1];
            int adjNode = iter[0];

            if (dist + edgeWeight < result[adjNode])
            {
                result[adjNode] = dist + edgeWeight;
                pq.push({result[adjNode], adjNode});
            }
        }
    }
    return result;
}

int main()
{
    int const nodes = 6;
    vector<vector<int>> adj[nodes];
    // graph syntax:  node -> {Adjacent node, Edge weight}
    
    adj[0] = {{1, 4}, {2, 4}};
    adj[1] = {{0, 4}, {2, 2}};
    adj[2] = {{0, 4}, {1, 2}, {3, 3}, {4, 1}, {5, 6}};
    adj[3] = {{2, 3}, {5, 2}};
    adj[4] = {{2, 1}, {5, 3}};
    adj[5] = {{3, 2}, {2, 6}, {4, 3}};

    cout << "Input Graph: " << endl;
    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for (auto &j : adj[i])
        {
            cout << "{" << j[0] << " ," << j[1] << "} ";
        }
        cout << endl;
    }
    cout << endl;

    int startVertex = 0;

    vector<int> result = Dijkstra(nodes, adj, startVertex);

    cout << "Output: " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Vertex: " << i << ", Distance from Starting vertex " << startVertex << " is: " << result[i] << endl;
    }

    return 0;
}