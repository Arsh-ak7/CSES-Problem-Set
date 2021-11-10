#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string ds = "RLDU";

int n, m;

bool possible(int x, int y)
{
    return (x < n && x >= 0 && y < m && y >= 0);
}

void dfs(vector<vector<int>> grid, vector<vector<int>> &visited, int i, int j)
{
    if (!possible(i, j) || visited[i][j] == 1 || grid[i][j] == 0)
        return;
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        dfs(grid, visited, i + dx[k], j + dy[k]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '.')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
    }
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && visited[i][j] == 0)
            {
                dfs(grid, visited, i, j);
                count++;
            }
        }
    }
    cout << count;
}