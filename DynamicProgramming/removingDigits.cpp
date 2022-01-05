// 1. Recurision

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

int recursiveRemovingDigits(int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT64_MAX;
    string num = to_string(n);
    int min_count = 1e9;
    for (auto ch : num)
    {
        if (ch != '0')
            min_count = min(min_count, 1 + recursiveRemovingDigits(n - (ch - '0')));
    }

    return min_count;
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
    cout << recursiveRemovingDigits(n);
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

int recursiveRemovingDigitsMemo(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT64_MAX;
    if (dp[n] != -1)
        return dp[n];
    string num = to_string(n);
    int min_count = 1e9;
    for (auto ch : num)
    {
        if (ch != '0')
            min_count = min(min_count, 1 + recursiveRemovingDigitsMemo(n - (ch - '0'), dp));
        dp[n] = min_count;
    }

    return dp[n];
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
    vector<int> dp(n + 1, -1);
    cout << recursiveRemovingDigitsMemo(n, dp);
    return 0;
}

// 3. DP

#include <iostream>
#include <vector>

using namespace std;

int minRemovals(int n)
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
    int n;
    cin >> n;
    cout << minRemovals(n) << '\n';
}