#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long num;
    stack<pair<int, long long>> s;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        while (!s.empty() && s.top().second >= num)
            s.pop();

        if (s.empty())
            cout << 0 << " ";
        else
            cout << s.top().first << " ";
        s.push({i + 1, num});
    }
}