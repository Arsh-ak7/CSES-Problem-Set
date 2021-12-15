#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<pair<long long, long long>> adj[100005];
long long dist[100005], visited[100005];

void calcDist(long long n)
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    long long src = 1;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        long long node = pq.top().second;
        pq.pop();
        if (visited[node])
            continue;
        visited[node] = 1;

        for (auto it : adj[node])
        {
            if (dist[it.first] > dist[node] + it.second)
            {
                dist[it.first] = dist[node] + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
}

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long n, m;
    cin >> n >> m;
    long long src, dest, wt;
    for (long long i = 0; i < m; i++)
    {
        cin >> src >> dest >> wt;
        adj[src].push_back({dest, wt});
    }
    // dist.resize(n + 1, INT32_MAX);
    // visited.resize(n + 1, false);
    for (long long i = 2; i <= n; i++)
    {
        dist[i] = __LONG_LONG_MAX__;
        visited[i] = 0;
    }

    calcDist(n);
    for (long long i = 1; i <= n; i++)
        cout << dist[i] << " ";
}