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
    Idea: So while cutting we can make the cuts either horizontally or vertically.
          While making horizontal cuts let the cut be at position k, so we have two blocks
          of size n * (m-k) and n * k and we made a cut so we add 1.
          similarly we can do for vertical cuts and return the minimum of two
*/

int rectangleCuttingRecur(int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (n == m)
        return 0;
    if (n == 1)
        return m - 1;
    if (m == 1)
        return n - 1;
    int leftMin = INT32_MAX, rightMin = INT32_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            leftMin = min(leftMin, rectangleCuttingRecur(n - j, m) + rectangleCuttingRecur(j, m) + 1); // Checking all possible cut lengths
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < i; j++)
        {
            rightMin = min(rightMin, rectangleCuttingRecur(n, m - j) + rectangleCuttingRecur(n, j) + 1);
        }
    }
    return min(leftMin, rightMin);
}

// MEMOIZATION

int rectangleCuttingMemo(int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (n == m)
        return 0;
    if (n == 1)
        return m - 1;
    if (m == 1)
        return n - 1;
    if (dp[n][m] != -1)
        return dp[n][m];

    int horizontalCut = INT32_MAX, verticalCut = INT32_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            horizontalCut = min(rectangleCuttingMemo(n - j, m, dp) + rectangleCuttingMemo(j, m, dp) + 1, horizontalCut);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < i; j++)
        {
            verticalCut = min(rectangleCuttingMemo(n, m - j, dp) + rectangleCuttingMemo(n, j, dp) + 1, verticalCut);
        }
    }
    return dp[n][m] = min(horizontalCut, verticalCut);
}

// DP

int rectangleCuttingDP(int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i - k][j] + dp[k][j] + 1, dp[i][j]);
                }
                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j - k] + dp[i][k] + 1, dp[i][j]);
                }
            }
        }
    }
    return dp[n][m];
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
    // cout << rectangleCuttingRecur(n, m);
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // cout << rectangleCuttingMemo(n, m, dp);
    cout << rectangleCuttingDP(n, m);
    return 0;
}