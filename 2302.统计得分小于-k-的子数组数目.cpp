/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int l = 0;
        long long res = 0L;
        long long sum = 0L;
        for (int r = 0; r < nums.size(); ++r)
        {
            sum += nums[r];
            while ((r - l + 1) * sum >= k)
            {
                sum -= nums[l];
                ++l;
            }
            res += r - l + 1;
        }
        return res;
    }
};
// @lc code=end
