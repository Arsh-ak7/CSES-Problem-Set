#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long a;
    vector<long long> v;
    long long totalSum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        v.push_back(a);
        totalSum += a;
    }
    long long ans = INT32_MAX;
    long long size = v.size();
    long long numberOfSubsets = 1 << size;
    for (long long bitMasked = 0; bitMasked < numberOfSubsets; ++bitMasked)
    {
        long long currentSetSum = 0;
        for (int j = 0; j < size; ++j)
        {
            if (bitMasked & (1 << j))
                currentSetSum += v[j];
        }
        ans = min(ans, abs((totalSum - currentSetSum) - currentSetSum));
    }
    cout << ans << endl;
}
