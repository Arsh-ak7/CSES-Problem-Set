#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<pair<long long, long long>, int>> times(n);
    long long arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> times[i].first.first >> times[i].first.second;
        times[i].second = i;
    }
    sort(times.begin(), times.end());
    priority_queue<pair<long long, long long>> pq;
    int rooms = 0, last_rooms = 0;
    for (int i = 0; i < n; ++i)
    {
        if (pq.empty())
        {
            last_rooms++;
            pq.push(make_pair(-times[i].first.second, last_rooms));
            arr[times[i].second] = last_rooms;
        }
        else
        {
            pair<long long, long long> minDept = pq.top();
            if (-minDept.first < times[i].first.first)
            {
                pq.pop();
                pq.push(make_pair(-times[i].first.second, minDept.second));
                arr[times[i].second] = minDept.second;
            }
            else
            {
                last_rooms++;
                pq.push(make_pair(-times[i].first.second, last_rooms));
                arr[times[i].second] = last_rooms;
            }
        }
        rooms = max(rooms, int(pq.size()));
    }
    cout << rooms << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}