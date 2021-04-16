#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long n;
    cin >> n;
    long long t;
    long long maxi = INT16_MIN;
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        if (maxi < t)
            maxi = t;
        sum += t;
    }
    cout << max(sum, 2 * maxi);
}