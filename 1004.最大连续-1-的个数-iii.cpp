/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0;
        int cnt = 0;
        int res = 0;
        for (int r = 0; r < nums.size(); ++r)
        {
            if (nums[r] == 0)
            {
                ++cnt;
            }
            while (cnt > k &&l <= r)
            {
                if (nums[l++] == 0)
                    --cnt;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end
