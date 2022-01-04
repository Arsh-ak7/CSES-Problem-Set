// 1. Recursion : TLE

#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#define int long long

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int recursiveCoinCombi(int arr[], int n, int target)
{
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;
    int count = 0;
    for (int j = 0; j < n; j++)
        count += recursiveCoinCombi(arr, n, target - arr[j]);

    return count;
}

signed main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, target;
    cin >> n >> target;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << recursiveCoinCombi(arr, n, target);
    return 0;
}

// 2. MEMO TLE

#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#define int long long

int MOD = 1e9 + 7;

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int recursiveCoinCombi(int arr[], int n, int target, vector<int> &dp, int i)
{
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;
    if (dp[target] != -1)
        return dp[target];
    int count = 0;
    for (int j = 0; j < n; j++)
        count += recursiveCoinCombi(arr, n, target - arr[j], dp, j) % MOD;

    return dp[target] = count % MOD;
}

signed main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, target;
    cin >> n >> target;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(target + 1, -1);
    cout << recursiveCoinCombi(arr, n, target, dp, 0);
    return 0;
}

// DP : CORRECT

#include <iostream>
#include <vector>

using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int MOD = 1e9 + 7;
    int n, target;
    cin >> n >> target;
    vector<int> c(n);
    for (int &v : c)
        cin >> v;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - c[j] >= 0)
            {
                (dp[i] += dp[i - c[j]]) %= MOD;
            }
        }
    }
    cout << dp[target];
}