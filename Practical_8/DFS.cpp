#include <bits/stdc++.h>
using namespace std;
void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    visited[node] = true;
    cout << node << " ";
    for(int next : graph[node])
    {
        if(!visited[next])
            DFS(next, graph, visited);
    }
}
int main()
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<int>> graph(n);
    cout << "Enter edges:\n";
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    vector<bool> visited(n, false);
    auto startTime = chrono::high_resolution_clock::now();
    cout << "\nDFS Traversal: ";
    DFS(start, graph, visited);
    auto stopTime = chrono::high_resolution_clock::now();
    double time = chrono::duration<double, milli>
                  (stopTime - startTime).count();
    cout << fixed << setprecision(6);
    cout << "\nExecution Time: " << time << " milliseconds";
    cout << "\nTime Complexity: O(V + E)";
    cout << "\nSpace Complexity: O(V)";
    return 0;
}