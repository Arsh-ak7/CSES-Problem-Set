#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// RECURSION

void moneySumsRecur(int n, int arr[], int index, set<int> &ans, int curr)
{
    if (index == n)
    {
        if (curr != 0)
            ans.insert(curr);
        return;
    }
    curr += arr[index];
    moneySumsRecur(n, arr, index + 1, ans, curr);
    curr -= arr[index];
    moneySumsRecur(n, arr, index + 1, ans, curr);
}

// DP

int moneySumsDP(int n, int arr[])
{
    vector<vector<int>> dp(n + 1, vector<int>(1000 * n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1000 * n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i - 1] >= 0 && dp[i - 1][j - arr[i - 1]] == 1)
                dp[i][j] = 1;
        }
    }
    vector<int> ans;
    for (int j = 1; j <= 1000 * n; j++)
        if (dp[n][j])
            ans.push_back(j);
    cout << ans.size() << endl;

    for (int i : ans)
        cout << i << " ";
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
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // set<int> s;
    // moneySumsRecur(n, arr, 0, s, 0);
    // cout << s.size() << '\n';
    // for (auto &i : s)
    //     cout << i << " ";
    moneySumsDP(n, arr);
    return 0;
}