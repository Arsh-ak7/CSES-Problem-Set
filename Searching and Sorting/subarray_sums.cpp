#include <iostream>
#include <unordered_map>

using namespace std;

long long calcSums(long long arr[], long long n, long long x)
{
    unordered_map<long long, long long> mp;
    long long count = 0;
    long long currSum = 0;
    for (int i = 0; i < n; ++i)
    {
        currSum += arr[i];
        if (currSum == x)
            count++;
        if (mp.count(currSum - x))
            count += (mp[currSum - x]);
        mp[currSum]++;
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, x;
    cin >> n >> x;
    long long arr[n];
    for (long long i = 0; i < n; ++i)
        cin >> arr[i];
    cout << calcSums(arr, n, x) << endl;
}