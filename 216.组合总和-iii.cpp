/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    int map[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> path;
        int sum = 0;
        bool flag = false;
        function<void(int)> dfs = [&](int i)
        {

            if (sum == n && path.size() == k)
            {
                res.push_back(path);
                return;
            }
            if (sum == n || path.size() == k)
            {
                return;
            }
            if (sum > n)
            {
                return;
            }
            if (i == 10)
            {
                return;
            }

            dfs(i + 1);
            sum += i;
            path.push_back(i);
            dfs(i + 1);
            sum -= i;
            path.pop_back();
        };

        dfs(1);
        return res;
    }
};
// @lc code=end
