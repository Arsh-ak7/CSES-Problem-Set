#include <iostream>
#include <set>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class type1>
using ordered_multiset = tree<type1, null_type, less_equal<type1>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    int n, k;
    cin >> n >> k;
    long long arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    ordered_multiset<long long> st;
    queue<long long> q;
    for (int i = 0; i < n; ++i)
    {
        if (q.size() == k)
        {
            if (k & 1)
            {
                cout << *(st.find_by_order(k / 2)) << " ";
            }
            else
                cout << *(st.find_by_order(k / 2 - 1)) << " ";
            long long front = q.front();
            st.erase(st.find_by_order(st.order_of_key(front)));
            q.pop();
        }
        q.push(arr[i]);
        st.insert(arr[i]);
    }
    if (k & 1)
    {
        cout << *(st.find_by_order(k / 2)) << " ";
    }
    else
        cout << *(st.find_by_order(k / 2 - 1)) << " ";
}