#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{

    vector<int> dist(V, 1e8);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (vector<int> edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            return { -1 };
        }
    }

    return dist;
}

int main()
{
    int v, e;
    cout << "Enter the number of vertex and edges: ";
    cin >> v >> e;
    vector<vector<int>> edges;

    cout << "Input the vertex and their weight (u, v , weight):" << endl;

    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int src = 0;
    vector<int> ans = bellmanFord(v, edges, src);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Vertex: " << i << " Distance: " << ans[i] << endl;
    }
    return 0;
}