/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> res(spells.size(), 0);
        sort(potions.begin(), potions.end());
        for (size_t i = 0; i < spells.size(); i++)
        {
            long long  target = ((success  - 1) / spells[i]) +1 ;
            int rt = lower_bound1(potions, target);
            cout << "target = " << target << " rt = " << rt << endl;

            res[i] =  potions.size() - rt;
        }
        return res;
    }

    int lower_bound1(vector<int> &nums, long long target)
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
