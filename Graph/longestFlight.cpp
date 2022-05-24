#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

vector<int> adj[100005];

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void dfs(int src, vector<int> &vis, vector<int> &dp, int n, vector<int> &res)
{
    vis[src] = 1;
    if (src == n)
        return;
    for (auto &it : adj[src])
    {
        if (!vis[it])
            dfs(it, vis, dp, n, res);
        if (dp[it] > dp[src])
        {
            dp[src] = dp[it];
            res[src] = it;
        }
    }
    if (dp[src] > 0)
        dp[src]++;
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
    }
    vector<int> vis(n + 1, 0);
    vector<int> dp(n + 1, 0);
    vector<int> res(n + 1, -1);
    dp[n] = 1;
    dfs(1, vis, dp, n, res);
    if (dp[1] == 0)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << dp[1] << '\n';
        int i = 1;
        while (i != -1)
        {
            cout << i << " ";
            i = res[i];
        }
    }

    return 0;
}