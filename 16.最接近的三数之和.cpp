/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int dec = 13001;
        int res = -1;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i)
        {

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int s = nums[i] + nums[i + 1] + nums[i + 2];

            if (s > target)
            {
                if (s - target < dec)
                {
                    res = s;
                }
                break;
            }
            s = nums[i] + nums[nums.size() - 2] + nums[nums.size() - 1];
            if (s < target)
            {
                if (target - s < dec)
                {
                    dec = target - s;
                    res = s;
                }
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                {
                    return target;
                }
                else if (sum < target)
                {
                    if (target - sum < dec)
                    {
                        dec = target - sum;
                        res = sum;
                    }
                    ++left;
                }
                else
                {
                    if (sum - target < dec)
                    {
                        dec = sum - target;
                        res = sum;
                    }
                    --right;
                }
            }
        }

        return res;
    }
};
// @lc code=end
