/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int target_1 = 0;
        int target_2 = 1;

        int res1 = lower_bound(nums, target_1);
        int res2 = nums.size() - lower_bound(nums, target_2);
        return max(res1, res2);
    }

    int lower_bound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end
