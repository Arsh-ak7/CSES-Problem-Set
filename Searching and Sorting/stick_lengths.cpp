#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if (n % 2 == 0)
    {
        int mid1 = n / 2;
        int mid2 = mid1 - 1;
        long long ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            ans1 += abs(arr[mid1] - arr[i]);
            ans2 += abs(arr[mid2] - arr[i]);
        }
        cout << min(ans1, ans2);
    }
    else
    {
        int mid = n / 2;
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(arr[mid] - arr[i]);
        cout << ans;
    }
}