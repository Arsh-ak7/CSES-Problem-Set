#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    multiset<long long> st;
    long n, m;
    cin >> n >> m;
    long long a;
    for (long i = 0; i < n; ++i)
    {
        cin >> a;
        st.insert(a);
    }
    for (long i = 0; i < m; ++i)
    {
        cin >> a;
        auto it = st.upper_bound(a);
        if (it == st.begin())
            cout << -1 << endl;
        else
        {
            cout << *(--it) << endl;
            st.erase(it);
        }
    }
}