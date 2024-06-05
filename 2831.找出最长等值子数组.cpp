/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 *
 * [2831] 找出最长等值子数组
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        unordered_map<int, vector<int>> map;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i]) == 0)
            {
                map[nums[i]] = {};
            }
            auto item = map.find(nums[i]);
            item->second.push_back(i);
        }

        int res = 0;
        for (auto it : map)
        {
            int left = 0;
            for (int right = 0; right < it.second.size(); ++right)
            {
                while (it.second[right] - it.second[left] - right + left > k)
                {
                    ++left;
                }
                res = res > right - left + 1 ? res : right - left + 1;
            }
        }
        return res;
    };
};
// @lc code=end
