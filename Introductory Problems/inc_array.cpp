#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    long arr[t];
    for (int i = 0; i < t; i++)
        cin >> arr[i];
    long moves = 0;
    for (int i = 0; i < t; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            moves += arr[i] - arr[i + 1];
            arr[i + 1] = arr[i];
        }
        else
            continue;
    }
    cout << moves;
}