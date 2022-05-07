#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// RECURSION
/*
We ideally want to check for each possible currVal in the range [1, m] can we have that number in that position or not.
We can only replace the value which either is currVal == arr[index] or have arr[index] as 0.
arr[index] === 0 means that we can replace the value in that position by any value we want so we can always have an array
Essence of having arr[index] === currVal and returning 1 is for diff to be zero between the numbers
*/

int arrayDescRecur(int arr[], int n, int m, int currVal, int index)
{
    if (currVal < 0) // If currVal is negative we return 0
        return 0;
    if (currVal > m || currVal == 0 || index >= n) // Constraint Violations
        return 0;

    if (index == n - 1) // If we reach the end of our array we see whether
    {
        if (arr[index] == currVal || arr[index] == 0) // 0 means that we can replace by any number we want and if its equal to current we say that we can replace that as well else its fixed.
            return 1;
        else
            return 0;
    }

    int ans = 0;
    if (arr[index] == currVal || arr[index] == 0)
        ans = arrayDescRecur(arr, n, m, currVal + 1, index + 1) + arrayDescRecur(arr, n, m, currVal, index + 1) + arrayDescRecur(arr, n, m, currVal - 1, index + 1);

    return ans;
}

// MEMOIZATION

int arrayDescMemo(int arr[], int n, int m, int currVal, int index, vector<vector<int>> &dp)
{
    if (currVal < 0 || currVal > m || currVal == 0 || index < 0 || index >= n)
        return 0;

    if (dp[index][currVal] != -1)
        return dp[index][currVal];

    dp[index][currVal] = 0;

    if (index == n - 1)
    {
        if (arr[index] == currVal || arr[index] == 0)
            return dp[index][currVal] = 1;
        else
            return dp[index][currVal] = 0;
    }
    int ans = 0;
    if (arr[index] == currVal || arr[index] == 0)
    {
        (ans = (arrayDescMemo(arr, n, m, currVal + 1, index + 1, dp) % MOD + arrayDescMemo(arr, n, m, currVal, index + 1, dp) % MOD) % MOD + arrayDescMemo(arr, n, m, currVal - 1, index + 1, dp) % MOD) %= MOD;
    }
    return dp[index][currVal] = ans;
}

// DP

int arrayDescDP(int arr[], int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = 1;
            if (i == 1)
            {
                if (arr[i - 1] == j || arr[i - 1] == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else
            {
                if (arr[i - 1] == j || arr[i - 1] == 0)
                    (dp[i][j] = ((dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD + dp[i - 1][j + 1] % MOD)) %= MOD;
                else
                    dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        (ans += dp[n][i] % MOD) %= MOD;

    return ans;
}

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // int ans = 0;
    // for (int i = 0; i <= m; i++)
    //     ans += arrayDescRecur(arr, n, m, i, 0);
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // for (int i = 0; i <= m; i++)
    //     (ans += arrayDescMemo(arr, n, m, i, 0, dp)) %= MOD;
    // cout << ans;
    cout << arrayDescDP(arr, n, m);
    return 0;
}