/*
 * @lc app=leetcode.cn id=2981 lang=cpp
 *
 * [2981] 找出出现至少三次的最长特殊子字符串 I
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumLength(string s)
    {
        unordered_map<string, int> map;
        int left = 0;
        int right = 0;
        while (right < s.size())
        {
            if (s[right] == s[left])
            {
                int tmp = right - left + 1;
                while (tmp > 0)
                {
                    cout << s.substr(left, tmp) << endl;
                    ++map[s.substr(left, tmp)];
                    --tmp;
                }
                ++right;
            }
            else
            {
                left = right;
            }
        }

        int res = 0;
        for (auto item : map)
        {

            if (item.second >= 3)
            {

                if (res < item.first.size())
                {
                    res = item.first.size();
                }
                
            }
        }
        return res ==0 ? -1 : res;
    }
};
// @lc code=end