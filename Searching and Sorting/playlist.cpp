#include <iostream>
#include <map>

using namespace std;

// long long max(long long a, long long b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    cin >> n;
    map<long long, long long> mp;
    long long arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    long long ans = 0;
    for (long long i = 0, j = 0; i < n; ++i)
    {
        //cout << mp[arr[i]] << " ";
        j = max(mp[arr[i]], j);
        //cout << j << " ";
        ans = max(ans, i - j + 1);
        mp[arr[i]] = i + 1;
        //cout << mp[arr[i]] << endl;
    }
    cout << ans;
}