/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxN = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            maxN = maxN > nums[i] ? maxN : nums[i];
        }
        cout << "maxN:" << maxN << endl;

        int cnt = 0;
        long long ans = 0;

        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] == maxN)
            {
                ++cnt;
            }
            for (; cnt >= k; l++)
            {
                if (nums[l] == maxN)
                {
                    --cnt;
                }
            }
            ans += l;
        }
        return ans;
    }
};
// @lc code=end
