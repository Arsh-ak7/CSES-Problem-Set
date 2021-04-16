#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long t;
    cin >> t;
    long long arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    long long low = 0, high = 1e18;
    long long ans = 0;
    while (low <= high)
    {
        long long mid = (high + low) / 2;
        long long prods = 0;
        for (int i = 0; i < n; i++)
        {
            prods += mid / arr[i];
            if (prods >= t)
                break;
        }
        if (prods >= t)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}