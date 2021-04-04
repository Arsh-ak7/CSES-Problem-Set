#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n;
    cin >> n;
    long long x, arr[n];
    cin >> x;
    for (long i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    long long count = 0;
    long i = 0;
    long j = n - 1;
    while (i <= j)
    {
        if (arr[i] + arr[j] <= x)
        {
            count++;
            i++;
            j--;
        }
        else if (arr[j] <= x)
        {
            count++;
            j--;
        }
    }
    cout << count;
}