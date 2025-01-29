#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS
void topologicalSortUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &Stack)
{
    visited[v] = true; // current node

    for (int i : adj[v])
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }
    Stack.push(v);
}

// Function to perform Topological Sort
void topologicalSort(vector<vector<int>> &adj, int v)
{
    stack<int> Stack;
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }

    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    int v, e;

    // v is number of vertex
    // e is number of edges

    cout << "Enter the number of vertex: ";
    cin >> v;

    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges;
    vector<vector<int>> adj(v);

    cout << "Enter edges: " << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "\t";
        cin >> u >> v;
        edges.push_back({u, v});
    }

    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
    }

    cout << "Topological sorting of the graph: ";
    topologicalSort(adj, v);
}