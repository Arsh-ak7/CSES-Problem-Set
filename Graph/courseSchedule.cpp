#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int MOD = 1e9 + 7;

vector<int> adj[100005];

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, e;
    cin >> n >> e;
    int src, dest;
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest;
        adj[src].push_back(dest);
    }
    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int &it : adj[i])
            indegree[it]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int &it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (ans.size() != n)
        cout << "IMPOSSIBLE\n";
    else
    {
        for (auto &it : ans)
            if (it != 0)
                cout << it << " ";
    }
    return 0;
}