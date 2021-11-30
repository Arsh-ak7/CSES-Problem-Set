#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;

void buildTree(long long segTree[], long long index, long long low, long long high, long long arr[])
{
    if (low == high)
    {
        segTree[index] = arr[low];
        return;
    }

    long long mid = (low + high) / 2;
    buildTree(segTree, 2 * index, low, mid, arr);
    buildTree(segTree, 2 * index + 1, mid + 1, high, arr);

    segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
}

long long query(long long segTree[], long long index, long long low, long long high, long long l, long long r)
{
    if (l <= low && r >= high)
        return segTree[index];

    if (high < l || low > r)
        return 0;

    long long mid = (low + high) / 2;

    long long left = query(segTree, 2 * index, low, mid, l, r);
    long long right = query(segTree, 2 * index + 1, mid + 1, high, l, r);
    return left + right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, q;
    cin >> n >> q;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    long long segTree[4 * n] = {0};
    buildTree(segTree, 1, 0, n - 1, arr);
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        l--, r--;
        long long ans = query(segTree, 1, 0, n - 1, l, r);
        cout << ans << '\n';
    }

    return 0;
}

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

    return query(2 * node, node_low, last_in_left, l, r) + query(2 * node + 1, last_in_left + 1, node_high, l, r);
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
    for (int i = n - 1; i >= 1; i--)
        tree[i] = tree[2 * i] + tree[2 * i + 1];

    while (q--)
    {
        int low, high;
        cin >> low >> high;
        low--, high--;
        cout << query(1, 0, n - 1, low, high) << "\n";
    }
}