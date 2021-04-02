#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long factorial(long n)
{
    long long ans = 1;
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int arr[26] = {0};
    long long number;
    long long denominator = 1;
    for (int i = 0; i < s.length(); i++)
        arr[s[i] - 97]++;
    for (int i = 0; i < 26; i++)
        denominator *= factorial(arr[i]);
    cout << factorial(s.length()) / denominator << endl;
    ;
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}