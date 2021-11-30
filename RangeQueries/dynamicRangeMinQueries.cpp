#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d)                                                               \
    for (                                                                       \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second;                                                       \
        debug("%s: %d ms\n", d, (int)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false)

using namespace std;

// long long buildTree(long long segTree[], long long index, long long low, long long high, long long arr[])
// {
//     if (low == high)
//     {
//         return segTree[index] = arr[low];
//     }
//     else
//     {
//         long long mid = (low + high) / 2;
//         return segTree[index] = min(buildTree(segTree, 2 * index, low, mid, arr), buildTree(segTree, 2 * index + 1, mid + 1, high, arr));
//     }
// }

// long long query(long long segTree[], long long index, long long low, long long high, long long l, long long r)
// {
//     if (l <= low && r >= high)
//         return segTree[index];

//     if (high < l || low > r)
//         return INT_MAX;

//     long long mid = (low + high) / 2;

//     return min(query(segTree, 2 * index, low, mid, l, r), query(segTree, 2 * index + 1, mid + 1, high, l, r));
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     long long n, q;
//     cin >> n >> q;
//     long long arr[n];
//     for (long long i = 0; i < n; i++)
//         cin >> arr[i];
//     long long segTree[4 * n] = {0};
//     // time__("Curr")
//     // {
//     buildTree(segTree, 1, 0, n - 1, arr);
//     while (q--)
//     {
//         long long l, r;
//         cin >> l >> r;
//         l--, r--;
//         long long ans = query(segTree, 1, 0, n - 1, l, r);
//         cout << ans << '\n';
//     }
//     // }
//     // return 0;
// }

vector<long long> tree;

long long query(int node, int node_low, int node_high, int l, int r)
{
    if (l <= node_low && r >= node_high)
    {
        return tree[node];
    }

    if (node_high < l || r < node_low)
        return INT32_MAX;

    int last_in_left = (node_low + node_high) / 2;

    return min(query(2 * node, node_low, last_in_left, l, r), query(2 * node + 1, last_in_left + 1, node_high, l, r));
}

void update(int n, int i, int v)
{
    tree[n + i] = v;
    for (int j = (n + i) / 2; j >= 1; j /= 2) // dividing j by 2 basically helps to move from leaf to parent and grandparent and so on...
        tree[j] = min(tree[2 * j], tree[2 * j + 1]);
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
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);

    while (q--)
    {
        int mask, low, high;
        cin >> mask >> low >> high;
        if (mask == 1)
        {
            int k = low;
            int val = high;
            k--;
            update(n, k, val);
        }
        else
        {
            low--, high--;
            cout << query(1, 0, n - 1, low, high) << "\n";
        }
    }
}
