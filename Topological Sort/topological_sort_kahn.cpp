#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &adj, int v)
{
    vector<int> indegree(v);

    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> result;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (result.size() != v)
    {
        cout << "Graph contains cycle!" << endl;
        return {};
    }

    return result;
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
    vector<int> vec = topologicalSort(adj, v);

    for (auto i : vec)
    {
        cout << i << " ";
    }
    
}