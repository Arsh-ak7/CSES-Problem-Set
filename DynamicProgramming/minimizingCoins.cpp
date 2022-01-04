// RECURSION :
#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define int long long

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int helper(int arr[], int target, int n)
{
    if (target == 0)
        return 0;
    int res = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= target)
        {
            int temp_ans = helper(arr, target - arr[i], n);
            res = min(res, temp_ans + 1);
        }
    }
    return res;
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
    int ans = helper(arr, target, n);
    if (ans == 1e9)
        cout << "-1";
    else
        cout << ans;
    return 0;
}

// DP : MEMOIZATION

#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define int long long

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int helper(int arr[], int target, int n, vector<int> &dp)
{
    if (target == 0)
        return 0;
    if (dp[target] != -1)
        return dp[target];
    int res = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= target)
        {
            int temp_ans = helper(arr, target - arr[i], n, dp);
            res = min(res, temp_ans + 1);
        }
    }
    return dp[target] = res;
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
    vector<int> dp(target + 1, -1);
    int ans = helper(arr, target, n, dp);
    if (ans == 1e9)
        cout << "-1";
    else
        cout << ans;
    return 0;
}

/*
    3. Dynamic Programming tabulation
*/

#include <iostream>
#include <vector>

using namespace std;

signed main()
{
    int n, target;
    cin >> n >> target;
    vector<int> c(n);
    for (int &v : c)
        cin >> v;

    vector<int> dp(target + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - c[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    cout << (dp[target] == 1e9 ? -1 : dp[target]) << endl;
}