#pragma GCC optimize("O2")
#include <iostream>

using namespace std;

long long rangeOutput(long long arr[], int a, int b)
{
    if (a == 1)
        return arr[b - 1];
    if (a == b)
        return arr[b - 1] - arr[b - 2];
    return arr[b - 1] - arr[a - 2];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    long long currSum[n];
    long long tempSum = 0;
    for (int i = 0; i < n; i++)
    {
        long long inp;
        cin >> inp;
        tempSum += inp;
        currSum[i] = tempSum;
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << rangeOutput(currSum, a, b) << '\n';
    }
}