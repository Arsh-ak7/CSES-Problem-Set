// 1. Recursion

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

int recursiveCoin(int arr[], int target, int n, int index)
{
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;

    int count = 0;
    for (int i = index; i < n; i++)
    {
        count += recursiveCoin(arr, target - arr[i], n, i);
    }
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
        cin >> arr[i];

    cout << recursiveCoin(arr, target, n, 0);
    return 0;
}

// 2. MEMO

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

int MOD = 1e9 + 7;

int recursiveCoinMemo(int arr[], int target, int n, int index, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;
    if (dp[index][target] != -1)
        return dp[index][target];
    int count = 0;
    for (int i = index; i <= n; i++)
    {
        count += recursiveCoinMemo(arr, target - arr[i - 1], n, i, dp) % MOD;
        dp[i][target] = count % MOD;
    }
    // cout << index << " " << target << " " << count << endl;
    return dp[index][target];
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
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    // sort(arr, arr + n);
    dp[0][0] = 1;
    recursiveCoinMemo(arr, target, n, 1, dp);
    cout << dp[n][target];
    return 0;
}

// 3. Dynamic Programming

#include <iostream>
#include <vector>

using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int mod = 1e9 + 7;
    int n, target;
    cin >> n >> target;
    vector<int> x(n);
    for (int &v : x)
        cin >> v;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - x[i - 1];
            if (left >= 0)
            {
                (dp[i][j] += dp[i][left]) %= mod;
            }
        }
    }
    cout << dp[n][target] << endl;
}