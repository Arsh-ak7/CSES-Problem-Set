#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long MOD = 1e9 + 7;
    long long n;
    cin >> n;
    long long dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= 6 && i - j >= 0; j++)
            (dp[i] += dp[i - j]) %= MOD;
    }
    cout << dp[n];
}