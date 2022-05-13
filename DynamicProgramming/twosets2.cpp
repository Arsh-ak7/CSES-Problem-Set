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

int ways = 0;

void twoSetsRecur(int n, int arr[], int targetSum, int index, int curr)
{
    if (index == n)
    {
        return;
    }
    if (curr == targetSum)
    {
        ways++;
        return;
    }
    curr += arr[index];
    twoSetsRecur(n, arr, targetSum, index + 1, curr);
    curr -= arr[index];
    twoSetsRecur(n, arr, targetSum, index + 1, curr);
}

void twoSetsDP(int n, int arr[], int targetSum)
{
    vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= targetSum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i - 1] >= 0)
                (dp[i][j] += dp[i - 1][j - arr[i - 1]]) %= MOD;
        }
    }
    cout << dp[n - 1][targetSum]; // n-1 as if we take n then it would count everything as twice and so basically by leaving the last element
                                  // we make sure it always stays on the different sets so no duplicates
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
    {
        arr[i] = i + 1;
    }
    long long sum = n * (n + 1) / 2;
    if (sum % 2 == 1)
        cout << 0 << endl;
    else
    {
        long long targetSum = sum / 2;
        // twoSetsRecur(n, arr, targetSum, 0, 0);
        // cout << ways;
        twoSetsDP(n, arr, targetSum);
    }
    return 0;
}