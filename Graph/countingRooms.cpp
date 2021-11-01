/*
    Idea : Iterate over every . and find wherever you can traverse dfsly
*/

#pragma GCC optimize("O2")
#include <iostream>
using namespace std;

int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};

int n, m, answer = 0;
int vis[1010][1010];
char grid[1010][1010];

bool isValid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '#')
        return false;
    return true;
}

void DFS(int y, int x)
{
    vis[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + neighborX[i];
        int newY = y + neighborY[i];
        if (isValid(newY, newX))
        {
            if (!vis[newY][newX])
            {
                DFS(newY, newX);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            vis[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                DFS(i, j);
                answer++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}

// Time and space -> O(n*m)