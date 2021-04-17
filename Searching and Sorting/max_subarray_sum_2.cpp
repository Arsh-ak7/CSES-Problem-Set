#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a, b;
    cin >> a >> b;
    long long pre[n];
    long long currSum = 0;
    long long inp;
    for (long long i = 0; i < n; ++i)
    {
        cin >> inp;
        currSum += inp;
        pre[i] = currSum;
    }
    multiset<long long> ms;
    ms.insert(0);
    long long ans = -9e18;
    ans = max(ans, pre[a - 1]);
    int flag = 0;
    for (long long i = a; i < n; ++i)
    {
        if (i - b >= 0)
        {
            if (flag == 0)
            {
                ms.erase(ms.find(0));
                flag = 1;
            }
        }
        if (i - a >= 0)
            ms.insert(pre[i - a]);
        ans = max(ans, pre[i] - *ms.begin());

        if (i - b >= 0)
        {
            ms.erase(ms.find(pre[i - b]));
        }
    }
    cout << ans << endl;
}