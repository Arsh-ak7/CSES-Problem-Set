// RECURSIVE APPROACH

#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

#define int long long

int MOD = 1e9 + 7;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int minimizingCoinsRecur(int n, int arr[], int sm)
{
    if (sm == 0)
        return 0;

    int ans = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= sm)
            ans = min(ans, minimizingCoinsRecur(n, arr, sm - arr[i]) + 1);
    }
    return ans;
}

// MEMOIZATION

int minimizingCoinsMemo(int n, int arr[], int sm, int dp[])
{
    if (sm == 0)
        return 0;

    if (dp[sm] != -1)
        return dp[sm];

    int ans = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= sm)
        {
            ans = min(ans, minimizingCoinsMemo(n, arr, sm - arr[i], dp) + 1);
        }
    }
    return dp[sm] = ans;
}

// DP

int minimizingCoinsDP(int n, int arr[], int sm, int dp[])
{
    dp[0] = 0;
    for (int i = 1; i <= sm; i++)
    {
        dp[i] = INT32_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i - arr[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }
    return dp[sm];
}

signed main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, sm;
    cin >> n >> sm;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[sm + 1];
    memset(dp, 1e9, sizeof(dp));

    // int ans = minimizingCoinsRecur(n, arr, sm);
    // int ans = minimizingCoinsMemo(n, arr, sm, dp);
    int ans = minimizingCoinsDP(n, arr, sm, dp);
    if (ans == INT32_MAX)
        cout << -1;
    else
        cout << ans;
    return 0;
}