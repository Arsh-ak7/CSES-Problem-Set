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

/*
    Idea: here A has two options either the front or back of array, now if he choses the front part then,
          The next available would be the min we get if B choses the first element so first + 2 or he choses the
          back element so front + 1 and back - 1;
          Similar is the case when A choses the back.
          Why min because B tries to minimize the score of A so he would only chose that digit that would reseult in the
          lowest score of A.
*/

int removalGameRecur(int n, int arr[], int front, int back)
{
    if (front > back)
        return 0;
    int resA = arr[front] + min(removalGameRecur(n, arr, front + 2, back), removalGameRecur(n, arr, front + 1, back - 1));
    int resB = arr[back] + min(removalGameRecur(n, arr, front, back - 2), removalGameRecur(n, arr, front + 1, back - 1));

    return max(resA, resB);
}

// DP

/*
    Idea: We make a table table of size n * n and store the diff between the total and min of the points that player 2
    can get for that array.
*/

void removalGameDp(int n, int arr[])
{
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    vector<long long> prefixSums(n, 0);
    for (long long i = 0; i < n; i++)
    {
        dp[i][i] = arr[i];
        prefixSums[i] = arr[i];
        if (i > 0)
            prefixSums[i] += prefixSums[i - 1];
    }

    for (long long size = 2; size <= n; size++)
    {
        for (long long i = size - 1; i < n; i++)
        {
            long long total = i < size ? prefixSums[i] : prefixSums[i] - prefixSums[i - size];
            long long selectFirst = total - dp[i - size + 2][i];
            long long selectLast = total - dp[i - size + 1][i - 1];
            dp[i - size + 1][i] = max(selectFirst, selectLast);
        }
    }
    cout << dp[0][n - 1] << endl;
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
        cin >> arr[i];

    // cout << removalGameRecur(n, arr, 0, n - 1);
    removalGameDp(n, arr);
    return 0;
}