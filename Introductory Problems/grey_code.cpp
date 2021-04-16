#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    for (int i = 2; i < (1 << n); i = i << 1)
    {
        for (int j = i - 1; j >= 0; --j)
            v.push_back(v[j]);
        for (int j = 0; j < i; ++j)
            v[j] = "0" + v[j];
        for (int j = i; j < 2 * i; ++j)
            v[j] = "1" + v[j];
    }
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
}