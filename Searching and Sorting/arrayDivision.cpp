#pragma GCC("O2")

#include <iostream>
#include <vector>
#include <map>
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d)                                                               \
    for (                                                                       \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second;                                                       \
        debug("%s: %d ms\n", d, (int)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false)

using namespace std;

bool binarySearch(long long arr[], long long mid, int k, int n)
{
    long long currSum = 0, currCount = 1;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum > mid)
        {
            currCount++;
            currSum = arr[i];
            if (currCount > k)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long arr[n];
    long long minVal = INT32_MIN, maxVal = 0, curr;
    for (int i = 0; i < n; i++)
    {
        cin >> curr;
        arr[i] = curr;
        minVal = max(minVal, curr);
        maxVal += curr;
    }
    while (minVal < maxVal)
    {
        long long mid = minVal + (maxVal - minVal) / 2;
        if (binarySearch(arr, mid, k, n))
            maxVal = mid;
        else
            minVal = mid + 1;
    }

    cout << minVal << '\n';
}