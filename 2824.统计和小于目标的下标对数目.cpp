/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 *
 * [2824] 统计和小于目标的下标对数目
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= 0 && nums[i] >= target)
            {
                return res;
            }

            int r = nums.size() - 1;
            while (i < r)
            {

                int sum = nums[i] + nums[r];
                if (sum < target)
                {
                    
                    res += r - i;
                    break;
                }
                --r;
            }
        }
        return res;
    }
};
// @lc code=end
