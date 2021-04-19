#include <iostream>

using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;
    long long arr[n];
    long long min = INT32_MAX;
    for (long long i = 0; i < n; ++i)
    {
        cin >> arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    long long start = 0;
    long long count = 0;
    long long currSum = arr[0] + abs(min);
    for (long long i = 1; i <= n; ++i)
    {
        while (currSum - (i - start) * abs(min) > x && start < i)
        {
            currSum -= (arr[start] + abs(min));
            start++;
        }
        if (currSum - (i - start) * abs(min) == x)
            count++;

        if (i < n)
        {
            currSum += (arr[i] + abs(min));
        }
    }
    cout << count;
}