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

long long buildTree(long long segTree[], long long index, long long low, long long high, long long arr[])
{
    if (low == high)
    {
        return segTree[index] = arr[low];
    }
    else
    {
        long long mid = (low + high) / 2;
        return segTree[index] = min(buildTree(segTree, 2 * index, low, mid, arr), buildTree(segTree, 2 * index + 1, mid + 1, high, arr));
    }
}

long long query(long long segTree[], long long index, long long low, long long high, long long l, long long r)
{
    if (l <= low && r >= high)
        return segTree[index];

    if (high < l || low > r)
        return INT_MAX;

    long long mid = (low + high) / 2;

    return min(query(segTree, 2 * index, low, mid, l, r), query(segTree, 2 * index + 1, mid + 1, high, l, r));
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
    // time__("Curr")
    // {
    buildTree(segTree, 1, 0, n - 1, arr);
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        l--, r--;
        long long ans = query(segTree, 1, 0, n - 1, l, r);
        cout << ans << '\n';
    }
    // }
    // return 0;
}