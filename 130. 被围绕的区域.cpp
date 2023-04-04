#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,1,-1,0};
    void solve(vector<vector<char>> &board)
    {
        int rowSize = board.size();
        int colSize = board[0].size();
        vector<vector<char>> result(rowSize, vector<char>(colSize, 'X'));
        vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
        queue<pair<int, int>> q;
        for (size_t i = 0; i < colSize; i++)
        {
            if (board[0][i] == 'O')
            {
                q.push({0, i});
                visited[0][i] = 1;
                result[0][i] = 'O';
            }
            if (board[rowSize - 1][i] == 'O')
            {
                q.push({rowSize - 1, i});
                visited[rowSize-1][i] = 1;
                result[rowSize-1][i] = 'O';
            }
        }
        for (size_t i = 0; i < rowSize; i++)
        {
            if (i != 0 || i != rowSize - 1)
            {
                if (board[i][0] == 'O')
                {
                    q.push({i, 0});
                    visited[i][0] = 1;
                    result[i][0] = 'O';
                }
                if (board[i][colSize-1] == 'O')
                {
                    q.push({i,colSize-1});
                    result[i][colSize-1] = 'O';
                    visited[i][colSize-1] =1;
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (size_t i = 0; i < 4; ++i)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx>0 && tx <rowSize&& ty>0 && ty<colSize)
                {
                    if (board[tx][ty] == 'X')
                    {
                        continue;
                    }
                    if (visited[tx][ty] == 1)
                    {
                        continue;
                    }
                    
                    q.push({tx,ty});
                    visited[tx][ty]= 1;
                    result[tx][ty] = 'O';
                }
            }
        }
        board = result;
    }
};