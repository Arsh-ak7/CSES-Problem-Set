#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long n;
    cin >> n;
    multiset<long long> ms;
    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        auto it = ms.upper_bound(x);
        if (it == ms.end())
            ms.insert(x);
        else
        {
            ms.erase(it);
            ms.insert(x);
        }
    }
    cout << ms.size();
}