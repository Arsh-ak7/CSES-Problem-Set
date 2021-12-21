#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <queue>

#define int long long

const long long inf = 1000000000000;

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void shortestDistance(vector<vector<int>> &matrix, int n)
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] >= inf)
                matrix[i][j] = -1;
        }
    }
}

signed main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    int src, dest, wt;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, inf));
    for (int i = 0; i < m; i++)
    {
        cin >> src >> dest >> wt;
        adj[src][src] = 0,
        adj[dest][dest] = 0;
        adj[src][dest] = min(adj[src][dest], wt);
        adj[dest][src] = min(adj[src][dest], wt);
    }
    shortestDistance(adj, n);
    while (k--)
    {
        cin >> src >> dest;
        cout << adj[src][dest] << '\n';
    }
    return 0;
}