#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

// RECURSION:
/*
    i, j represents the index upto which we are comparing and getting the minimum, so for i it's min operations needed to
    construct the string s2 till j from s1 till ith index.
*/

int editDistanceRecur(string s1, string s2, int i, int j)
{
    if (i < 0) // if s1 exhausted we need j+1 insertions to get s2 till j [j+1 as 0 based indexing is considered]
        return j + 1;
    if (j < 0) // similarly if s2 exhausted we need i+1 deletions from s1 to get s2
        return i + 1;
    if (s1[i] == s2[j])
        return editDistanceRecur(s1, s2, i - 1, j - 1);
    else
        return min({1 + editDistanceRecur(s1, s2, i, j - 1), 1 + editDistanceRecur(s1, s2, i - 1, j), 1 + editDistanceRecur(s1, s2, i - 1, j - 1)});
}

// MEMO

int editDistanceMemo(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = editDistanceRecur(s1, s2, i - 1, j - 1);
    else
        return dp[i][j] = min({1 + editDistanceRecur(s1, s2, i, j - 1), 1 + editDistanceRecur(s1, s2, i - 1, j), 1 + editDistanceRecur(s1, s2, i - 1, j - 1)});
}

// DP

/*
    dp[0][0] = 0 as to make s2 of length 0 from s1 of length 0 requires 0 moves
    dp[0][j] = j as we need j operations to make s2 of length j from s1 of length s1
    similarly for dp[i][0]=i
    dp[i-1][j]  corresponds to deletion of char from s1 to make s2;
    dp[i][j-1] corresponds to addition of char to s1 to make s2;
    dp[i-1][j-1] corresponds to replacing a char in s1 to make s2;
*/

int editDistanceDP(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int j = 1; j <= m; j++)
        dp[0][j] = j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({1 + dp[i - 1][j], 1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]});
        }
    }
    return dp[n][m];
}

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    // cout << editDistanceRecur(s1, s2, n - 1, m - 1);
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << editDistanceMemo(s1, s2, n - 1, m - 1, dp);
    cout << editDistanceDP(s1, s2, n, m);
    return 0;
}