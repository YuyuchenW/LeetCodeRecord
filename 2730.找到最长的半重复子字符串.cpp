/*
 * @lc app=leetcode.cn id=2730 lang=cpp
 *
 * [2730] 找到最长的半重复子字符串
 */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int res = 1;
        int l = 0;
        int cnt = 0;
        for (int r = 1; r < s.size(); ++r)
        {
            if (s[r] == s[r - 1] && ++cnt > 1)
            {
                for (l++; s[l - 1] != s[l]; ++l)
                {
                    cnt = 1;
                }
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end
