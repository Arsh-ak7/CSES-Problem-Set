#pragma GCC optimize("O2")

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void bfs(vector<int> adj[], vector<int> &par, vector<bool> &visited, int node)
{
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto v : adj[temp])
        {
            if (!visited[v])
            {
                visited[v] = true;
                par[v] = temp;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> adj[100006];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> par(n + 1, -1);
    vector<bool> visited(n + 1, false);

    bfs(adj, par, visited, 1);
    vector<int> ans;

    if (par[n] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    stack<int> st;
    int node = n;
    while (node != -1)
    {
        st.push(node);
        node = par[node];
    }
    cout << st.size() << '\n';
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}