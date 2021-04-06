#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long a;
    long long max_sum = INT32_MIN;
    long long current_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        current_sum = max(current_sum + a, a);
        max_sum = max(current_sum, max_sum);
    }
    cout << max_sum;
}