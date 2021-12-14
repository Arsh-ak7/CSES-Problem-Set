#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> adj[100005];

vector<int> cyc;

bool dfs(vector<bool> &visited, int node, int parent)
{
    visited[node] = true;

    for (int it : adj[node])
    {
        cyc.push_back(it);
        if (!visited[it])
        {
            if (dfs(visited, it, node))
                return true;
        }
        else if (it != parent)
            return true;
        cyc.pop_back();
    }

    return false;
}

void findCycle(vector<bool> &visited, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cyc.push_back(i);
        if (!visited[i] && dfs(visited, i, 0))
        {
            vector<int> ans = {*cyc.rbegin()};
            for (auto j = cyc.rbegin() + 1; j != cyc.rend(); j++)
            {
                ans.push_back(*j);
                if (*j == *cyc.rbegin())
                    break;
            }

            cout << ans.size() << '\n';
            for (int it : ans)
                cout << it << " ";

            return;
        }
        cyc.pop_back();
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int src, dest;
    for (int i = 0; i < m; i++)
    {
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    vector<bool> visited(n + 1, false);
    findCycle(visited, n);

    return 0;
}