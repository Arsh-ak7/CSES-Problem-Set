#pragma GCC optimize("O2")

#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

vector<int> adj[100005];

void dfs(vector<int> adj[], int src, vector<int> &visited)
{
    visited[src] = true;
    for (auto it : adj[src])
    {
        if (!visited[it])
            dfs(adj, it, visited);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int src, dest;

    for (int i = 0; i < m; i++)
    {
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    vector<int> visited(n + 1, false);
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == false)
        {
            ans.push_back(i);
            dfs(adj, i, visited);
        }
    }
    cout << ans.size() - 1 << '\n';
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i] << " " << ans[i] - 1 << '\n';
    }
}