#pragma GCC optimize("O2")

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[100005];

#define fast_cin()                   \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);                    \
   cout.tie(NULL)

bool bfs(vector<int> &color, int src)
{
   color[src] = 1;
   queue<int> q;
   q.push(src);
   while (!q.empty())
   {
      int node = q.front();
      q.pop();
      for (int it : adj[node])
      {
         if (color[it] == -1)
         {
            color[it] = 1 - color[node];
            q.push(it);
         }
         else if (color[it] == color[node])
            return false;
      }
   }
   return true;
}

bool biPartism(vector<int> &color, int n)
{
   for (int i = 1; i <= n; i++)
   {
      if (color[i] == -1)
      {
         if (!bfs(color, i))
            return false;
      }
   }
   return true;
}

int main()
{
   fast_cin();
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int n, m;
   cin >> n >> m;
   int src, dest;
   for (int i = 0; i < m; i++)
   {
      cin >> src >> dest;
      adj[src].push_back(dest);
      adj[dest].push_back(src);
   }
   vector<int> ans(n, 1);
   vector<int> color(n + 1, -1);
   if (!biPartism(color, n + 1))
      cout << "IMPOSSIBLE" << '\n';
   else
   {
      for (int i = 1; i <= n; i++)
      {
         if (color[i] == 0)
            ans[i - 1] = 2;
      }
      for (auto it : ans)
         cout << it << " ";
   }

   return 0;
}