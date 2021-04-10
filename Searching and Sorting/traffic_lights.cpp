#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<long> ms;
    ms.insert(x);
    long a;
    while (n--)
    {
        cin >> a;
        auto it = s.lower_bound(a);
        auto it2 = it;
        --it2;
        ms.erase(ms.find(*it - *it2));
        ms.insert(a - *it2);
        ms.insert(*it - a);
        cout << *--ms.end() << " ";
        s.insert(a);
    }
}