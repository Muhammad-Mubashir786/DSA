#include <iostream>
#include <vector>
using namespace std;
void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor, adj, visited);
        }
    }
}
int main()
{
    int V = 7;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5, 6};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};
    adj[6] = {2};
    vector<bool> visited(V, false);
    cout << "DFS traversal: ";
    DFS(0, adj, visited);
    return 0;
}