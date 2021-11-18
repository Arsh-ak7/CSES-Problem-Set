#pragma GCC optimize("O2")

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<long long> countSum(n, 0);
    long long currSum = 0;
    countSum[0]++;
    for (int i = 0; i < n; i++)
    {
        currSum = (((currSum + arr[i]) % n) + n) % n; //Necessary to handle negative sum
        countSum[currSum]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += countSum[i] * (countSum[i] - 1) / 2;
    }

    cout << ans << '\n';
}