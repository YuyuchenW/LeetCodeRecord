/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int res = 0;
        if (nums.size() < 3)
        {
            return res;
        }

        sort(nums.begin(), nums.end());
        for (int i = 2; i < nums.size(); ++i)
        {
            int l = 0, r = i - 1;
            int x = nums[i];
            while (l < r)
            {
                if (nums[r] + nums[l] > x)
                {
                    res += r - l;
                    --r;
                }
                else
                {
                    ++l;
                }
            }
        }
        return res;
    }
};
// @lc code=end
