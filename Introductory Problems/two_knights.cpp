#include <iostream>

using namespace std;

long long square(long long n)
{
    return n * n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int t = 1;
    while (t <= n)
    {
        cout << (square(t) * (square(t) - 1)) / 2 - 4 * (t - 1) * (t - 2) << endl;
        t++;
    }
}