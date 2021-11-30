#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;

vector<long long> tree;

long long query(int node, int node_low, int node_high, int l, int r)
{
    if (l <= node_low && r >= node_high)
        return tree[node];

    if (l > node_high || r < node_low)
        return 0;

    int last_in_left = (node_low + node_high) / 2;

    return query(2 * node, node_low, last_in_left, l, r) ^ query(2 * node + 1, last_in_left + 1, node_high, l, r);
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (__builtin_popcount(n) != 1)
    {
        arr.push_back(0);
        n++;
    }

    tree.resize(2 * n, 0);

    // BUILD TREE
    for (int i = 0; i < n; i++)
        tree[n + i] = arr[i];

    for (int i = n - 1; i >= 1; i--)
        tree[i] += tree[2 * i] ^ tree[2 * i + 1];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(1, 0, n - 1, l, r) << '\n';
    }
}