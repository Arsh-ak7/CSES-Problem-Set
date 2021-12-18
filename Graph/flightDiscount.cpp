#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <queue>

#define int long long

const int inf = 10000000000000000LL;

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<pair<int, int>> adj[100005];
vector<pair<int, int>> invert[100005];
int visited[100005];

void dijkstra(int src, vector<int> &dist, int n, vector<pair<int, int>> adj[])
{
    memset(visited, 0, sizeof visited);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        // cout << node.first << " " << node.second << endl;
        if (visited[node.second])
            continue;
        visited[node.second] = 1;
        for (auto it : adj[node.second])
        {
            if (dist[it.first] > dist[node.second] + it.second)
            {
                dist[it.first] = dist[node.second] + it.second;
                pq.push({dist[it.first], it.first});
            }
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

    int n, m;
    cin >> n >> m;
    int src, dest, wt;
    vector<vector<int>> tp;
    vector<int> dist(n + 1, inf);
    vector<int> invDist(n + 1, inf);
    for (int i = 0; i < m; i++)
    {
        cin >> src >> dest >> wt;
        adj[src].push_back({dest, wt});
        invert[dest].push_back({src, wt});
        tp.push_back({src, dest, wt});
    }

    dijkstra(1, dist, n, adj);
    dijkstra(n, invDist, n, invert);
    long long ans = inf;

    for (auto it : tp)
    {
        ans = min(ans, (dist[it[0]] + invDist[it[1]] + it[2] / 2));
    }

    cout << ans << '\n';
    return 0;
}