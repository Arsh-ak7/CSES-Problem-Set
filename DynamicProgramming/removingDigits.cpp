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