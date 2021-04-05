#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sortbysec(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
    return (a.second < b.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n;
    cin >> n;
    long long a, b;
    vector<pair<long long, long long>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), sortbysec);
    long long r1 = v[0].second;
    long count = 1;
    for (long i = 1; i < v.size(); i++)
    {
        long long l1 = v[i].first;
        long long r2 = v[i].second;
        if (l1 >= r1)
        {
            count++;
            r1 = r2;
        }
    }
    cout << count;
}