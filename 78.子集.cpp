/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include<vector>
#include<functional>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        function<void(int)> fun = [&](int n){
            if ( n == nums.size())
            {
                res.push_back(path);
                return;
            }
            fun(n+1);
            path.push_back(nums[n]);
            fun(n+1);
            path.pop_back();
            return;
        };

        fun(0);

        return res;
    }
};
// @lc code=end

