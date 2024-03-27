/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 *
 * [2439] 最小化数组中的最大值
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int maxN = *max_element(nums.begin(), nums.end());

        auto check = [&](int n) -> bool
        {
            long long extra = 0;
            for (int i = nums.size() - 1; i > 0; i--)
            {
                extra = max(nums[i] - n + extra, 0ll);
            }
            return extra + nums[0] <= n;
        };

        int left = 0, right = maxN;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(mid))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
