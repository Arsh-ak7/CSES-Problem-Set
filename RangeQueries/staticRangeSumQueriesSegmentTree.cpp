#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

using namespace std;

void buildTree(vector<int> &segTree, int index, int low, int high, int arr[])
{
    if (low == high)
    {
        segTree[index] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    buildTree(segTree, 2 * index, low, mid, arr);
    buildTree(segTree, 2 * index + 1, mid + 1, high, arr);

    segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
}

int query(vector<int> segTree, int index, int low, int high, int l, int r)
{
    if (l <= low && r >= high)
        return segTree[index];

    if (high < l || low > r)
        return 0;

    int mid = (low + high) / 2;

    int left = query(segTree, 2 * index, low, mid, l, r);
    int right = query(segTree, 2 * index + 1, mid + 1, high, l, r);
    return left + right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> segTree(4 * n, 0);
    buildTree(segTree, 1, 0, n - 1, arr);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = query(segTree, 1, 0, n - 1, l, r);
        cout << ans << '\n';
    }

    // return 0;
}