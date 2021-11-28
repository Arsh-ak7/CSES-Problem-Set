#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

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

    // return 0;
}