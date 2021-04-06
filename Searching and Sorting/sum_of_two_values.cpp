#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long n;
    cin >> n;
    long long x, a;
    cin >> x;
    vector<long long> v;
    map<int, int> val;
    for (long i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (val.count(x - v[i]))
        {
            cout << i + 1 << " " << val[x - v[i]] << endl;
            return 0;
        }
        val[v[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << endl;
}