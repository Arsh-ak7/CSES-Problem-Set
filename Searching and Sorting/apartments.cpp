#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n, m;
    long long k;
    cin >> n >> m >> k;
    long long arr[n], apt[m];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        cin >> apt[i];
    long count = 0;
    sort(arr, arr + n);
    sort(apt, apt + m);
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (abs(arr[i] - apt[j]) <= k)
        {
            ++i;
            ++j;
            ++count;
        }
        else
        {
            if ((arr[i] - apt[j]) > k)
                ++j;
            else
                ++i;
        }
    }
    cout << count << endl;
}