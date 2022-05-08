// RECURSION

#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define int long long

int MOD = 1e9 + 7;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int coinCombinationRecur(int target, int n, int arr[])
{
    if (target == 0)
        return 1;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (target - arr[i] >= 0)
            count += coinCombinationRecur(target - arr[i], n, arr);
    }
    return count;
}

// MEMOIZATION

int coinCombinationMemo(int target, int n, vector<int> &arr, vector<int> &dp)
{
    if (target == 0)
        return 1;
    if (dp[target] != -1)
        return dp[target];

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (target - arr[i] >= 0)
        {
            (count += coinCombinationMemo(target - arr[i], n, arr, dp)) %= MOD;
        }
    }
    return dp[target] = count;
}

// DP

int coinCombinationDP(int target, int n, vector<int> &arr, vector<int> &dp)
{
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (i - arr[j] >= 0)
            {
                (dp[i] += dp[i - arr[j]]) %= MOD;
            }
        }
    }
    return dp[target] % MOD;
}

signed main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, target;
    cin >> n >> target;
    vector<int> c(n);
    for (int &v : c)
        cin >> v;

    vector<int> dp(target + 1, -1);
    // dp[0] = 1;
    // for (int i = 1; i <= target; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i - c[j] >= 0)
    //         {
    //             (dp[i] += dp[i - c[j]]) %= MOD;
    //         }
    //     }
    // }
    // cout << dp[target];
    // cout << coinCombinationMemo(target, n, c, dp);
    cout << coinCombinationDP(target, n, c, dp);
}