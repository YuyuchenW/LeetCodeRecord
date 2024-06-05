/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {

        vector<int> leftVec;
        vector<int> rightVec;
        int left = 0;
        int right = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            leftVec.push_back(left);
            rightVec.push_back(right);
            if (s[i] == '1')
            {
                ++left;
            }
            if (s[s.size() - i - 1] == '0')
            {
                ++right;
            }
        }

        int res = INT_MAX;
        for (size_t i = 0; i < leftVec.size(); i++)
        {
            int tmp = leftVec[i] + rightVec[rightVec.size() - i - 1];
            res = res > tmp ? tmp : res;
        }
        return res;
    }
};
// @lc code=end
