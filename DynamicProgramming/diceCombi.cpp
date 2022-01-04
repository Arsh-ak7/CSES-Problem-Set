#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long MOD = 1e9 + 7;
    long long n;
    cin >> n;
    long long dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= 6 && i - j >= 0; j++)
            (dp[i] += dp[i - j]) %= MOD;
    }
    cout << dp[n];
}

// MEMOIZATION : RUNTIME ERROR AS SUM MAY BE VERY LARGE

#pragma GCC optimize("O2")

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define int long long

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

long long MOD = 1e9 + 7;

int diceCombiRecur(int arr[], int n, int dp[])
{
    if (dp[n] != -1)
        return dp[n] % MOD;
    if (n == 0)
        return 1;
    int count = 0;
    for (int j = 0; j < 6; j++)
        if (n - arr[j] >= 0)
            count += diceCombiRecur(arr, n - arr[j], dp) % MOD;
    return dp[n] = count % MOD;
}

signed main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[] = {1, 2, 3, 4, 5, 6};
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    int count = 0;
    diceCombiRecur(arr, n, dp);
    cout << dp[n];
}