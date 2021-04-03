#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n;
    cin >> n;
    set<long long> s;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        s.insert(a);
    }
    cout << s.size() << endl;
}