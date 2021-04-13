#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long t;
    cin >> t;
    long long a, b;
    vector<pair<long, long>> v;
    for (long i = 0; i < t; ++i)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    long currDuration = 0;
    long prize = 0;
    for (auto x : v)
    {
        currDuration += x.first;
        prize += -currDuration + x.second;
    }
    cout << prize;
}