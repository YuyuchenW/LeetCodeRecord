/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 *
 * [2958] 最多 K 个重复元素的最长子数组
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int res = 0;
        unordered_map<int, int> map;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r)
        {
            map[nums[r]]++;

            while (map[nums[r]] > k)
            {
                map[nums[l]]--;
                ++l;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end
