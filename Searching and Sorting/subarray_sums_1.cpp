#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<long long> v;
    long long a;
    int count = 0;
    long long currSum = 0;
    unordered_map<long long, long long> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        currSum += a;
        if (currSum == x)
            count++;
        if (mp.find(currSum - x) != mp.end())
            count += (mp[currSum - x]);
        mp[currSum]++;
    }
    cout << count << endl;
}