/*
 * @lc app=leetcode.cn id=2009 lang=cpp
 *
 * [2009] 使数组连续的最少操作数
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; ++i)
        {
            if (nums[i + 1] - nums[i] > 1)
            {
                ans += nums[i + 1] - nums[i] - 1;
                nums[i + 1] = nums[i] + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
