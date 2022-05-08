/*
    Recursive approach
*/

#pragma GCC optimize("O2")

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) for (long blockTime = NULL; (blockTime == NULL ? (blockTime = clock()) != NULL : false); debug("%s:%.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

using namespace std;

#define int long long

int MOD = 1e9 + 7;

int diceCombinationsRecur(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    int count = 0;
    for (int i = 1; i <= 6; i++)
        count += diceCombinationsRecur(n - i);

    return count;
}

// CLASSIC RECURSION

// int diceCombinationsRecur(int n)
// {
//     if (n == 0)
//         return 1;
//     if (n < 0)
//         return 0;

//     return diceCombinationsRecur(n - 1) +
//            diceCombinationsRecur(n - 2) +
//            diceCombinationsRecur(n - 3) +
//            diceCombinationsRecur(n - 4) +
//            diceCombinationsRecur(n - 5) +
//            diceCombinationsRecur(n - 6);
// }

// MEMOIZATION

int diceCombinationsMemo(int n, int dp[])
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int count = 0;
    for (int i = 1; i <= 6; i++)
        count += diceCombinationsRecur(n - i) % MOD;

    return dp[n] = count % MOD;
}

// DP

int diceCombinationsDP(int n, int dp[])
{
    if (n <= 0)
        return 0;

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
                (dp[i] += dp[i - j]) %= MOD;
        }
    }
    return dp[n];
}

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

signed main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    // cout << diceCombinationsRecur(n) % MOD;
    // time__("memo time")
    // {
    //     cout << diceCombinationsMemo(n, dp);
    // }
    cout << diceCombinationsDP(n, dp);
    return 0;
}