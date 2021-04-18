#include <iostream>

using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;
    long long arr[n];
    for (long long i = 0; i < n; ++i)
        cin >> arr[i];
    long long start = 0;
    long long count = 0;
    long long currSum = arr[0];
    for (long long i = 1; i <= n; ++i)
    {
        while (currSum > x && start < i - 1)
        {
            currSum -= arr[start];
            start++;
        }
        if (currSum == x)
            count++;

        if (i < n)
        {
            currSum += arr[i];
        }
    }
    cout << count;
}