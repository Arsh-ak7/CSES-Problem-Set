#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#define int long long

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const long long inf = 1LL << 62;

struct Node
{
    int src, dest, wt;
    Node(int first, int second, int weight)
    {
        src = first;
        dest = second;
        wt = weight;
    }
};

vector<Node> adj;

void bellmannFord(int src, vector<int> &par, vector<int> &dist, int n)
{
    dist[0] = 0;
    dist[src] = 0;
    bool flag = false;
    int vertex;
    for (int i = 0; i < n; i++)
    {
        vertex = 0;
        for (auto it : adj)
        {
            if (dist[it.dest] > it.wt + dist[it.src])
            {
                par[it.dest] = it.src;
                dist[it.dest] = it.wt + dist[it.src];
                vertex = it.dest;
            }
        }
    }

    if (!vertex)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            vertex = par[vertex];

        vector<int> cycle;
        for (int i = vertex;; i = par[i])
        {
            cycle.push_back(i);
            if (i == vertex && cycle.size() > 1)
                break;
        }

        reverse(cycle.begin(), cycle.end());
        for (auto it : cycle)
            cout << it << " ";
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
    for (int i = 0; i < m; i++)
    {
        cin >> src >> dest >> wt;
        adj.push_back(Node(src, dest, wt));
    }

    vector<int> par(n + 1, 0);
    vector<int> dist(n + 1, inf);

    bellmannFord(1, par, dist, n);

    return 0;
}