#include <vector>
#include <queue>
#include <iostream>
#include <memory>
#include <cstring>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int cnt = 0;
        int min = 0;
        int dir_x[4] = {0, 1, 0, -1};
        int dir_y[4] = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        int rowSize = grid.size();
        int colSize = grid[0].size();
        for (size_t i = 0; i < rowSize; i++)
        {
            for (size_t j = 0; j < colSize; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(pair(i, j));
                    continue;
                }
                else if (grid[i][j] == 1)
                {
                    ++cnt;
                }
            }
        }
        while (!q.empty())
        {
            bool flag = false;
            int n = q.size();
            for (size_t i = 0; i < n; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (size_t i = 0; i < 4; i++)
                {
                    int tx = x + dir_x[i];
                    int ty = y + dir_y[i];
                    if (tx >= 0 && tx < rowSize && ty >= 0 && ty < colSize && grid[tx][ty] == 1)
                    {
                        grid[tx][ty] = 2;
                        q.push(pair(tx, ty));
                        flag = true;
                        --cnt;
                    }
                }
            }

            if (flag)
            {
                ++min;
            }
        }
        return cnt ? -1 : min;
    }
};