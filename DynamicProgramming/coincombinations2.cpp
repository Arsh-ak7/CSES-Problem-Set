#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// RECURSION

int coinCombinationRecur(int target, int n, int arr[], int j)
{
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;

    int count = 0;
    for (int i = j; i < n; i++)
    {
        count += coinCombinationRecur(target - arr[i], n, arr, i);
    }
    return count;
}

// MEMOIZATION

int coinCombinationMemo(int target, int n, int arr[], int index, vector<vector<int>> &dp)
{
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;
    if (dp[index][target] != -1)
        return dp[index][target];

    int count = 0;
    for (int i = index; i < n; i++)
    {
        (count += coinCombinationMemo(target - arr[i], n, arr, i, dp)) %= MOD;
    }

    return dp[index][target] = count % MOD;
}

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    // cout << coinCombinationRecur(target, n, arr, 0);
    // cout << coinCombinationMemo(target, n, arr, 0, dp);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i - 1] >= 0)
                (dp[i][j] += dp[i][j - arr[i - 1]]) %= MOD;
        }
    }

    cout << dp[n][target] << '\n';
}