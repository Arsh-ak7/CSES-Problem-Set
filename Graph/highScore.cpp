#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

struct node
{
    long long src, dest, wt;
    node(long long first, long long second, long long weight)
    {
        src = first;
        dest = second;
        wt = weight;
    }
};

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long dist[2501];
    int n, m;
    cin >> n >> m;
    vector<node> graph;
    long long src, dest, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> src >> dest >> wt;
        graph.push_back(node(src, dest, wt));
    }
    for (int i = 0; i < 2501; i++)
    {
        dist[i] = INT64_MIN;
    }
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : graph)
        {
            if (dist[it.src] != INT64_MIN && dist[it.dest] < dist[it.src] + it.wt)
                dist[it.dest] = dist[it.src] + it.wt;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : graph)
        {
            if (dist[it.src] != INT64_MIN && dist[it.dest] < dist[it.src] + it.wt)
            {

                dist[it.dest] = INT32_MAX;
            }
        }
    }

    if (dist[n] == INT32_MAX || dist[n] > 1e12)
        cout << "-1" << '\n';
    else
        cout << dist[n] << '\n';
}