#include <queue>
#include <vector>
using namespace std;
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        if (grid[0][0] == 1 && 1 == grid[rowSize - 1][colSize - 1])
        {
            return -1;
        }
        int result = 0;
        int dy[8] = {1, 0, 0, -1, 1, 1, -1, -1};
        int dx[8] = {0, 1, -1, 0, 1, -1, 1, -1};

        vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;

        while (!q.empty())
        {
            int qSize = q.size();
            for (size_t i = 0; i < qSize; i++)
            {
                int x = q.front().first;
                int y = q.front().second;

                if (x == rowSize - 1 && y == colSize - 1)
                {
                    return result + 1;
                }
                for (size_t k = 0; k < 8; k++)
                {
                    int tx = x + dx[k];
                    int ty = y + dy[k];
                    if (tx < 0 || tx >= rowSize || ty < 0 || ty >= colSize)
                    {
                        continue;
                    }
                    if (visited[tx][ty] == 1)
                    {
                        continue;
                    }
                    if (grid[tx][ty] == 1)
                    {
                        continue;
                    }
                    q.push({tx, ty});
                    visited[tx][ty] = 1;
                }
                q.pop();
            }
            result++;
        }
        return -1;
    }
};