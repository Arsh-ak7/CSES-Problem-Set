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

int removingDigitsRecur(int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return 0;

    int count = INT32_MAX;
    string num = to_string(n);
    for (char &c : num)
    {
        if (c != '0')
            count = min(count, (1 + removingDigitsRecur(n - c + '0')));
    }
    return count;
}

// MEMOIZATION

int removingDigitsMemo(int n, int dp[])
{
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int count = INT32_MAX;
    string num = to_string(n);
    for (char &c : num)
    {
        if (c != '0')
            count = min(count, 1 + removingDigitsMemo(n - c + '0', dp));
    }

    return dp[n] = count;
}

// DP

int removingDigitsDP(int n)
{
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (char c : to_string(i))
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
    }
    return dp[n];
}

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    // cout << removingDigitsRecur(n);
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    cout << removingDigitsDP(n);
    return 0;
}