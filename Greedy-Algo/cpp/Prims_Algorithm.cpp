#include <iostream>
#include <vector>
#include <map>
using namespace std;

void printMap(map<int, vector<pair<int, int>>> adj)
{
    for (auto &i : adj)
    {
        cout << i.first << " -> ";
        for (auto &j : i.second)
        {
            cout << "{" << j.first << " ," << j.second << "} ";
        }
        cout << endl;
    }
}
map<int, vector<pair<int, int>>> prims(map<int, vector<pair<int, int>>> adj)
{
    int n = adj.size();
    vector<int> key(n, INT32_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, 0);

    key[0] = 0;

    for (int i = 0; i < n; i++)
    {

        int min = INT32_MAX;
        int node;

        for (int j = 0; j < n; j++)
        {
            if (mst[j] == false && key[j] < min)
            {
                node = j;
            }
        }

        mst[node] = true;

        for (auto &i : adj[node])
        {
            int endNode = i.first;
            int weight = i.second;
            if (mst[endNode] == false && weight < key[endNode])
            {
                parent[endNode] = node;
                key[endNode] = weight;
            }
        }
    }

    map<int, vector<pair<int, int>>> result;
    for (int i = 1; i < n; i++)
    {
        result.insert({i, {{parent[i], key[i]}}});
    }
    return result;
}

int main()
{
    map<int, vector<pair<int, int>>> adj =
        // Graph syntax -> {Node, {{Adjacent Node, Weight}}}
        {
            {0, {{1, 5}, {2, 1}}},
            {1, {{0, 5}, {2, 3}}},
            {2, {{0, 1}, {1, 3}}}};

    cout << "Input Graph: " << endl;
    printMap(adj);

    cout << endl;
    map<int, vector<pair<int, int>>> result = prims(adj);
    cout << "Minimum Spanning tree is: " << endl;
    printMap(result);

    return 0;
}
