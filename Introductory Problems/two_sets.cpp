#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<long> s1;
    set<long> s2;
    long n;
    cin >> n;
    long sum = (n * (n + 1) / 2);
    for (int i = 1; i < n; i++)
        s1.insert(i);
    if (sum % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        long targetsum = sum / 2;
        long csum = 0;
        for (long i = n; i > 0; i--)
        {
            if (csum + i <= targetsum)
            {
                csum += i;
                s1.erase(i);
                s2.emplace(i);
            }
            else
            {
                continue;
            }
        }
        cout << "YES" << endl;
        cout << s1.size() << endl;
        for (auto it = s1.begin(); it != s1.end(); it++)
            cout << *it << " ";
        cout << endl;
        cout << s2.size() << endl;
        for (auto it = s2.begin(); it != s2.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}