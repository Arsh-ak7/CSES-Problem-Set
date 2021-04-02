#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> str;
    long n = str.length();
    long arr[26];
    for (int i = 0; i < 26; i++)
        arr[i] = 0;
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i] - 65]++;
    }
    int odd = 0;
    long index;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2 != 0)
        {
            odd++;
            index = i;
        }
    }
    if (odd > 1 || ((odd == 1) && str.length() % 2 == 0))
        cout << "NO SOLUTION" << endl;
    else
    {
        char ans[n];
        for (int i = 0; i < str.length(); i++)
        {
            ans[i] = 0;
        }
        int j = 0;

        if (odd == 1)
        {
            ans[n / 2] = index + 65;
            arr[index]--;
        }
        for (int i = 0; i < 26; i++)
        {
            while (arr[i] > 0)
            {
                ans[j] = i + 65;
                ans[n - j - 1] = i + 65;
                arr[i] -= 2;
                j++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%c", ans[i]);
        }
    }
}