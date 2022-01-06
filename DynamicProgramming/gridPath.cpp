// 1. RECURSION : TLE

#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define int long long

int MOD = 1e9 + 7;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int countGridPaths(vector<vector<char>> grid, int n, int r, int c)
{
    if (r == n - 1 && c == n - 1)
        return 1;
    if (r >= n || c >= n)
        return 0;
    if (grid[r][c] == '*')
        return 0;
    return countGridPaths(grid, n, r + 1, c) + countGridPaths(grid, n, r, c + 1);
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
    vector<vector<char>> grid;
    char ch;
    for (int i = 0; i < n; i++)
    {
        vector<char> line;
        for (int j = 0; j < n; j++)
        {
            cin >> ch;
            line.push_back(ch);
        }
        grid.push_back(line);
    }
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*')
        cout << 0 << endl;
    else
    {
        int ways = 0;
        ways = countGridPaths(grid, n, 0, 0);
        cout << ways;
    }
    return 0;
}

// 2. MEMO

#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define int long long

int MOD = 1e9 + 7;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int countGridPaths(vector<vector<char>> grid, int n, int r, int c, vector<vector<int>> &dp)
{
    if (r == n - 1 && c == n - 1)
        return 1;
    if (r >= n || c >= n)
        return 0;
    if (grid[r][c] == '*')
        return 0;
    if (dp[r][c] != -1)
        return dp[r][c];
    return dp[r][c] = countGridPaths(grid, n, r + 1, c, dp) + countGridPaths(grid, n, r, c + 1, dp);
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
    vector<vector<char>> grid;
    char ch;
    for (int i = 0; i < n; i++)
    {
        vector<char> line;
        for (int j = 0; j < n; j++)
        {
            cin >> ch;
            line.push_back(ch);
        }
        grid.push_back(line);
    }
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*')
        cout << 0 << endl;
    else
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        countGridPaths(grid, n, 0, 0, dp);
        cout << dp[0][0];
    }
    return 0;
}

// 3. DP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int MOD = 1e9 + 7;
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
        {
            if (row[j] == '.')
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
    cout << dp[n - 1][n - 1];
}