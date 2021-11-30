#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;

vector<long long> tree;

long long query(int node, int node_low, int node_high, int l, int r)
{
    if (l <= node_low && r >= node_high)
    {
        return tree[node];
    }

    if (node_high < l || r < node_low)
        return 0;

    int last_in_left = (node_low + node_high) / 2;
    // Here we are adding the current node and the also the child value to get the new value
    return tree[node] + query(2 * node, node_low, last_in_left, l, r) + query(2 * node + 1, last_in_left + 1, node_high, l, r);
}
void update_recursive(int node, int node_low, int node_high, int l, int r, int val) // recursion
{
    if (l <= node_low && r >= node_high)
    {
        tree[node] += val;
        return;
    }

    if (node_high < l || r < node_low)
        return;
    // We recursively update every required node.
    int last_in_left = (node_low + node_high) / 2;
    update_recursive(2 * node, node_low, last_in_left, l, r, val);
    update_recursive(2 * node + 1, last_in_left + 1, node_high, l, r, val);

    // tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (__builtin_popcount(n) != 1) // used to check if n is power of 2.
    {
        arr.push_back(0);
        n++;
    }

    tree.resize(2 * n);

    // Filling the leaf nodes
    for (int i = 0; i < n; i++)
        tree[n + i] = arr[i];
    // Filling the non-leaf nodes in a bottom up manner
    // for (int i = n - 1; i >= 1; i--)
    //     tree[i] = tree[2 * i] + tree[2 * i + 1];

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            a--, b--;
            update_recursive(1, 0, n - 1, a, b, u);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            cout << query(1, 0, n - 1, k, k) << '\n';
        }
    }
}