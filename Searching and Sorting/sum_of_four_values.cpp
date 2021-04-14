#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long sum, a;
    vector<pair<long long, long long>> v;
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(make_pair(a, i + 1));
    }
    int flag = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 3; ++i)
    {
        long long currSum = v[i].first;
        for (int m = i + 1; i < n - 2; ++m)
        {
            currSum += v[m].first;
            long long j = m + 1, k = v.size() - 1;
            while (j < k)
            {
                if (currSum + v[j].first + v[k].first == sum)
                {
                    cout << v[i].second << " " << v[m].second << " " << v[j].second << " " << v[k].second << endl;
                    flag = 1;
                    break;
                }
                else if (currSum + v[j].first + v[k].first < sum)
                    ++j;
                else
                    --k;
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            break;
    }
    if (flag == 0)
        cout << "IMPOSSIBLE";
}