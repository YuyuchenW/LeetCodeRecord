/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <vector>
using namespace std;
#include <algorithm>
// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
        {
            return {};
        }

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            long long x = nums[i];
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            long long s = x + nums[i + 1] + nums[i + 2] + nums[i + 3];

            if (s > target)
            {
                break;
            }
            s = x + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (s < target)
            {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                long long y = nums[j];
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                s = x + y + nums[j + 1] + nums[j + 2];
                if (s > target)
                {
                    break;
                }

                s = x + y + nums[n - 1] + nums[n - 2];

                if (s < target)
                {
                    continue;
                }

                int l = j + 1, r = n - 1;

                while (l < r)
                {
                    s =x + y + nums[l] + nums[r];

                    if (s > target)
                    {
                        --r;
                    }
                    else if (s < target)
                    {
                        ++l;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
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
        }

        return res;
    }
};
// @lc code=end
