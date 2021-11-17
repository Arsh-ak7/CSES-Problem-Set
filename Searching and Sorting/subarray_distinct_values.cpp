#pragma GCC("O2")

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d)                                                               \
    for (                                                                       \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second;                                                       \
        debug("%s: %d ms\n", d, (int)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false)

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long count = 0;
    // time__("curr")
    // {
    map<int, int> mp;
    long long l = 0, r = 0;
    while (r < n)
    {
        if (mp.find(arr[r]) == mp.end())
            mp[arr[r]] = 0;
        mp[arr[r]]++;
        while (mp.size() > k)
        {
            mp[arr[l]] = --mp[arr[l]];
            if (mp[arr[l]] == 0)
                mp.erase(arr[l]);
            ++l;
        }
        count += r - l + 1;
        ++r;
        //}
    }
    cout << count << '\n';
}