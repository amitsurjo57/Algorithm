#include <bits/stdc++.h>
using namespace std;

#define INF 9999

void printSolution(int v, int dist[][100]);

void floydWarshall(int v, int dist[][100])
{

    int i, j, k;

    for (k = 0; k < v; k++)
    {

        for (i = 0; i < v; i++)
        {

            for (j = 0; j < v; j++)
            {

                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(v, dist);
}

void printSolution(int v, int dist[][100])
{
    cout << "The following matrix shows the shortest distances between every pair of vertices" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << dist[i][j] << "   ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    int graph[100][100];
    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == INF)
                graph[i][j] = INF;
        }
    }

    floydWarshall(v, graph);
    return 0;
}