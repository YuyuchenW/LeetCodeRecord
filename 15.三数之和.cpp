/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        int size = nums.size();

        for (size_t i = 0; i < size - 2; i++)
        {
            int x = nums[i];

            if (i > 0 && x == nums[i - 1])
            {
                continue;
            }

            if (x + nums[i + 1] + nums[i + 2] > 0)
            {
                break;
            }

            if (x + nums[size - 1] + nums[size - 2] < 0)
            {
                continue;
            }

            int l = i + 1, r = size - 1;

            while (l < r)
            {
                int sum = x + nums[l] + nums[r];
                if (sum > 0)
                {
                    --r;
                }
                else if (sum < 0)
                {
                    ++l;
                }
                else
                {
                    res.push_back({x, nums[l], nums[r]});
                    ++l;
                    while (l < r && nums[l] == nums[l - 1])
                    {
                        ++l;
                    }
                    --r;
                    while (l < r && nums[r] == nums[r + 1])
                    {
                        --r;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
