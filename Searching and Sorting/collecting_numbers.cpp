#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long a[n], b[n];
    long ar;
    for (int i = 0; i < n; i++)
    {
        cin >> ar;
        a[i] = ar;
        b[ar - 1] = i;
    }
    long ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (b[i] < b[i - 1])
            ans += 1;
    }
    cout << ans;
}