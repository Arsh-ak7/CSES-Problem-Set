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

// RECURSION

int bookShopRecur(int x, int n, int prices[], int pages[], int index)
{
    if (x == 0 || index == n)
        return 0;

    if (prices[index] > x)
    {
        return bookShopRecur(x, n, prices, pages, index + 1);
    }
    else
    {
        return max(pages[index] + bookShopRecur(x - prices[index], n, prices, pages, index + 1), bookShopRecur(x, n, prices, pages, index + 1));
    }
}

// MEMO

int bookShopMemo(int x, int n, int prices[], int pages[], int index, vector<vector<int>> &dp)
{
    if (x < 0 || index > n)
        return 0;
    if (x == 0 || index == n)
        return 0;
    if (dp[x][index] != -1)
        return dp[x][index];

    if (prices[index] > x)
    {
        return dp[x][index] = bookShopRecur(x, n, prices, pages, index + 1);
    }
    else
        return dp[x][index] = max(pages[index] + bookShopRecur(x - prices[index], n, prices, pages, index + 1), bookShopRecur(x, n, prices, pages, index + 1));
}

// DP

int bookShopDP(int budget, int n, int prices[], int pages[])
{
    vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= budget; j++)
        {
            if (prices[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j - prices[i - 1]] + pages[i - 1], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][budget];
}

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    int price[n];
    int pages[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    // vector<vector<int>> dp(x + 1, vector<int>(n + 1, -1));
    // cout << bookShopRecur(x, n, price, pages, 0);
    // cout << bookShopMemo(x, n, price, pages, 0, dp);
    cout << bookShopDP(x, n, price, pages);
    return 0;
}