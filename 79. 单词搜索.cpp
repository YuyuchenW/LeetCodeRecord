#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    bool flag = false;
    void backTracking(vector<vector<char>> &board, string &word, int x, int y, int &cnt, vector<vector<bool>> &isVisited)
    {
        if (cnt == word.size())
        {
            flag = true;
            return;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
        {
            return;
        }
        if (word[cnt] != board[x][y] || isVisited[x][y])
        {
            return;
        }
        isVisited[x][y] = true;
        ++cnt;
        for (size_t i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            backTracking(board, word, tx, ty, cnt, isVisited);
        }
        isVisited[x][y] = false;
        --cnt;
    }
    bool exist(vector<vector<char>> &board, string word)
    {

        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    int cnt = 0;
                    vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
                    backTracking(board, word, i, j, cnt, isVisited);
                    if (flag)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};