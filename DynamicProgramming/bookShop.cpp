// 1. RECURSION

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

int booksRecursion(int books[], int prices[], int target, int n)
{
    if (n == 0 || target == 0)
    {
        return 0;
    }
    if (prices[n - 1] > target)
        return booksRecursion(books, prices, target, n - 1);
    else
        return max(books[n - 1] + booksRecursion(books, prices, target - prices[n - 1], n - 1), booksRecursion(books, prices, target, n - 1));
}

signed main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    int books[n], prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> books[i];

    cout << booksRecursion(books, prices, x, n);

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

int booksRecursion(int books[], int prices[], int target, int n, vector<vector<int>> &dp)
{
    if (n == 0 || target == 0)
    {
        return 0;
    }
    if (dp[n - 1][target] != -1)
        return dp[n - 1][target];
    if (prices[n - 1] > target)
        return dp[n - 1][target] = booksRecursion(books, prices, target, n - 1, dp);
    else
        return dp[n - 1][target] = max(books[n - 1] + booksRecursion(books, prices, target - prices[n - 1], n - 1, dp), booksRecursion(books, prices, target, n - 1, dp));
}

signed main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    int books[n], prices[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> books[i];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    booksRecursion(books, prices, x, n, dp);
    cout << dp[n - 1][x];
    return 0;
}

// . DYNAMIC PROGRAMMING

#include <iostream>
#include <vector>

using namespace std;

signed main()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    int price[n], pages[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - price[i - 1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
        }
    }
    cout << dp[n][x] << '\n';
}