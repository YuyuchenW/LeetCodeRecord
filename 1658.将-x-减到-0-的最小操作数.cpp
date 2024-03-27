/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum < x)
        {
            return -1;
        }
        int res = -1;
        int l = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum -= nums[i];
            while (sum < x)
            {
                sum += nums[l];
                ++l;
            }
            if (sum == x)
            {
                res = max(res, (i - l + 1));
            }
        }
        return res == -1 ? -1 : nums.size() - res;
    }
};
// @lc code=end
