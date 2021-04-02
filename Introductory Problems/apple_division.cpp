#include <iostream>

using namespace std;

long long calc(long long arr[], int i, long long sumCalc, long long sumTotal)
{
    if (i == 0)
        return abs(sumTotal - sumCalc - sumCalc);

    return min(calc(arr, i - 1, sumCalc + arr[i - 1], sumTotal), calc(arr, i - 1, sumCalc, sumTotal));
}

long long findMin(long long arr[], long n)
{
    long long sumTotal = 0;
    for (int i = 0; i < n; i++)
        sumTotal += arr[i];

    calc(arr, n, 0, sumTotal);
}

int main()
{
    long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findMin(arr, n);
}