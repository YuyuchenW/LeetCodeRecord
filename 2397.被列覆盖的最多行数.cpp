/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */
#include <functional>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect)
    {
        if (numSelect == matrix[0].size())
        {
            return matrix.size();
        }

        int res = 0;
        int pathLen = 0;
        vector<int> path(matrix[0].size(), 0);
        function<void(int)> dfs = [&](int index)
        {
            if (numSelect == pathLen)
            {
                int cnt = checkRow(matrix, path);
                res = max(cnt, res);
                return;
            }
            for (int i = index; i < matrix[0].size(); ++i)
            {
                path[i] = 1;
                ++pathLen;
                dfs(i + 1);
                path[i] = 0;
                --pathLen;
            }
        };
        dfs(0);
        return res;
    }

    int checkRow(vector<vector<int>> &matrix, vector<int> &path)
    {
        int n = matrix[0].size();
        int cnt = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            bool flag = true;

            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 1 && path[j] != 1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ++cnt;
            }
        }
        return cnt;
    }
};
// @lc code=end
