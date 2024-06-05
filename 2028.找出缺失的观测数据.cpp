/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for(const int & i : rolls)
        {
            sum += i;
        }
        int target = mean *(n+ rolls.size()) - sum;
        if (target < n || target > n *6)
        {
            return {};
        }
        vector<int> res(n,1);
        target -= n;
        size_t  index = 0;
        while (target != 0)
        {
            if (target >= 5)
            {
                res[index] = 6;
                target-= 5;
            }
            else{
                res[index] += target;
                target = 0;
            }
            ++index;
        }
        return res;
    }
};
// @lc code=end

