#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct project
{
    long long start, end, money;
};

static bool comp(project p1, project p2) // Sorting the projects by their end date
{
    return p1.end < p2.end;
}

long long find(project arr[], long long index) // finding the project latest to the current one
{
    long long left = 0, right = index - 1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (arr[mid].end < arr[index].start)
        {
            if (arr[mid + 1].end < arr[index].start)
                left = mid + 1;

            else
                return mid;
        }
        else
            right = mid - 1;
    }
    return -1;
}

long long MOD = 1e9 + 7;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n;
    cin >> n;
    project arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].end >> arr[i].money;

    sort(arr, arr + n, comp);
    vector<long long> dp(n + 1, 0);
    dp[0] = arr[0].money;
    for (long long i = 1; i < n; i++)
    {
        long long currMoney = arr[i].money;
        long long prevEvent = find(arr, i);
        if (prevEvent != -1)
            currMoney += dp[prevEvent];

        dp[i] = max(dp[i - 1], currMoney);
    }
    cout << dp[n - 1] << endl;
    return 0;
}