#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false); //all node false (not visited)
    queue<int> q;

    cout << "BFS Traversal: ";
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;
            
            while (!q.empty())
            {
                int node = q.front();
                cout << node << " ";
                q.pop();
                for (int neighbor : adj[node])
                {
                    if (!visited[neighbor])
                    {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }
    cout << endl;
}
int main()
{

    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    BFS(V, adj);
    return 0;
}