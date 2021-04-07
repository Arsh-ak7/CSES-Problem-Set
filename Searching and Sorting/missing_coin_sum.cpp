#include <iostream>
#include <algorithm>

using namespace std;

long long findSmallest(long long arr[], int n)
{
    long long res = 1;

    for (int i = 0; i < n && arr[i] <= res; i++)
        res = res + arr[i];

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cout << findSmallest(arr, n);
}