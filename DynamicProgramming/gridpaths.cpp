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

int gridPathRecur(vector<vector<int>> &grid, int n, int i, int j)
{

    if (i < 0 || j < 0 || i >= n || j >= n)
        return 0;
    if (i == n - 1 && j == n - 1)
        return 1;
    if (grid[i][j] == 0)
        return 0;

    return gridPathRecur(grid, n, i + 1, j) + gridPathRecur(grid, n, i, j + 1);
}

int gridPathMemo(vector<vector<int>> grid, int n, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return 0;
    if (i == n - 1 && j == n - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (grid[i][j] == 0)
        return 0;

    return dp[i][j] = gridPathMemo(grid, n, i + 1, j, dp) + gridPathMemo(grid, n, i, j + 1, dp);
}

int gridPathDp(vector<vector<int>> &grid, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                if (i > 0)
                    (dp[i][j] += dp[i - 1][j]) %= MOD;
                if (j > 0)
                    (dp[i][j] += dp[i][j - 1]) %= MOD;
            }
            else
                dp[i][j] = 0;
        }
    }
    return dp[n - 1][n - 1];
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
    vector<vector<int>> grid(n, vector<int>(n, 1));
    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ch;
            if (ch == '*')
                grid[i][j] = 0;
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0)
        cout << 0 << endl;
    else
    {
        // cout << gridPathRecur(grid, n, 0, 0);
        // cout << gridPathMemo(grid, n, 0, 0, dp);
        cout << gridPathDp(grid, n);
    }
    return 0;
}