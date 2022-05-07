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

// IMAGE : https://www.youtube.com/watch?v=51AkVn5Urno 4:46
/*
    Recuurance relation is
        An = 2*An-1 + Bn-1
        Bn = 4*Bn-1 + An-1
        Where An is for last row has both tiles belonging to the same block and Bn has both of them belonging to
        different blocks
*/

// RECURSION

// int countingTowersRecur(int n, int curr)
// {
//     if (n == 1)
//         return 2;
//     if (n == 2)
//         return 8;
// }

// DP

/*
    Here dp[i][0] represents first state for An and dp[i][1] as state for Bn
*/

long long dp[1000005][2] = {0};

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        dp[1][0] = 1;
        dp[1][1] = 1;
        if (dp[n][0] != 0)
            cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
        else
        {
            for (int i = 2; i <= n; i++)
            {
                (dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD);
                (dp[i][1] = (4 * dp[i - 1][1] + dp[i - 1][0]) % MOD);
            }
            cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
        }
    }
    return 0;
}