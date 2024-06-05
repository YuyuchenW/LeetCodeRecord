/*
 * @lc app=leetcode.cn id=2965 lang=cpp
 *
 * [2965] 找出缺失和重复的数字
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        vector<int> res(2, 0);
        int n = grid.size();
        vector<int> path(n * n, 0);
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                ++path[grid[i][j] - 1];
            }
        }

        for (size_t i = 0; i < path.size(); i++)
        {
            if (path[i] == 0)
            {
                res[1] = i+1;
            }
            else if (path[i] == 2)
            {
                res[0] = i+1;
            }
        }
        

        return res;
    }
};
// @lc code=end
