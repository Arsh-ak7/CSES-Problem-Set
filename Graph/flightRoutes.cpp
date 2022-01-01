#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

#define int long long

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const long long inf = 1LL << 62;

// struct Node
// {
//     int src, dest, wt;
//     Node(int first, int second, int weight)
//     {
//         src = first;
//         dest = second;
//         wt = weight;
//     }
// };

// vector<Node> adj;
vector<pair<int, int>> adj[100005];
vector<int> ans;

void flightRoutes(int src, int dest, int k, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int count = 0;
    pq.push({0, src});
    int visited[n + 1] = {0};
    while (!pq.empty() && visited[n] < k)
    {
        int curr = pq.top().second;
        int currCost = pq.top().first;
        pq.pop();
        visited[curr]++;
        if (curr == dest)
            ans.push_back(currCost);
        if (visited[curr] <= k)
        {
            for (auto it : adj[curr])
            {
                pq.push({currCost + it.second, it.first});
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
    int n, m, src, dest, wt, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> src >> dest >> wt;
        adj[src].push_back({dest, wt});
    }
    flightRoutes(1, n, k, n);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}