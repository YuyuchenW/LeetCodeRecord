#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        if (grid[x][y] == '0')
        {
            return;
        }
        grid[x][y] = '0';
        for (size_t i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size())
            {
                dfs(grid, tx, ty);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    q.push(pair(i, j));
                }
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (grid[x][y]=='1')
            {
                ++cnt;
                dfs(grid,x,y);
            }
        }
        return cnt;
    }
};