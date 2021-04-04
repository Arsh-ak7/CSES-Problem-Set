#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n;
    cin >> n;
    vector<pair<long long, long long>> v;
    long long a, b;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    vector<pair<long long, char>> data;
    for (long i = 0; i < n; i++)
    {
        data.push_back({v[i].first, 'x'});
        data.push_back({v[i].second, 'y'});
    }
    long long ans = 0, count = 0;
    sort(data.begin(), data.end());
    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i].second == 'x')
            count++;
        if (data[i].second == 'y')
            count--;
        ans = max(ans, count);
    }
    cout << ans;
}