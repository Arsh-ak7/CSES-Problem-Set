#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string n;
    cin >> n;
    long max = 0;
    long currentSum = 0;
    for (int i = 0; i < n.length() - 1; i++)
    {
        if (n[i] == n[i + 1])
        {
            currentSum += 1;
            if (currentSum > max)
                max = currentSum;
        }
        else
            currentSum = 0;
    }
    cout << max + 1;
}