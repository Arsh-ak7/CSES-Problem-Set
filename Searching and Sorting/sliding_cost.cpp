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
    for (int i = 0; i < k; ++i)
        st.insert(arr[i]);

    long long mid = *(st.find_by_order((k + 1) / 2 - 1));
    long long cost = 0;
    for (int i = 0; i < k; ++i)
        cost += abs(arr[i] - mid);
    cout << cost << " ";
    for (int i = 0; i < n - k; ++i)
    {
        st.erase(st.find_by_order(st.order_of_key(arr[i])));
        st.insert(arr[i + k]);
        long long md = *(st.find_by_order((k + 1) / 2 - 1));
        cost += abs(md - arr[i + k]) - abs(mid - arr[i]);
        if (!(k & 1))
            cost -= md - mid;
        mid = md;
        cout << cost << " ";
    }
}