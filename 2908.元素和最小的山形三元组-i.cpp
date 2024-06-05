
/*
 * @lc app=leetcode.cn id=2908 lang=cpp
 *
 * [2908] 元素和最小的山形三元组 I
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int res  = 150;

        for(int i = 1; i< nums.size()-1;++i)
        {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
            {
                res = min(nums[i] + nums[i-1] + nums[i+1], res);
                ++i;
            }
        }

        return  res == 150 ? -1 : res;
    }
};
// @lc code=end

