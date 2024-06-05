/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <functional>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> path;
        int sum;
        function<void(int)> dfs = [&](int k)
        {
            if (sum == target)
            {
                res.push_back(path);
                return;
            }

            if (sum > target)
            {
                return;
            }

            for (size_t i = k; i < candidates.size(); i++)
            {
                sum += candidates[i];
                path.push_back(candidates[i]);
                dfs(i);

                sum -= candidates[i];
                path.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end
