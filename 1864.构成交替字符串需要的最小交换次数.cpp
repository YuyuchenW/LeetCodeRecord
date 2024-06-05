/*
 * @lc app=leetcode.cn id=1864 lang=cpp
 *
 * [1864] 构成交替字符串需要的最小交换次数
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minSwaps(string s)
    {
        int i = 0;
        int j = 0;
        for (const char &c : s)
        {
            if (c == '0')
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        if (abs(i - j) > 1)
        {
            return -1;
        }
        if (i == j)
        {
            int t = compareFun(s, '0');
            int t1 = compareFun(s, '1');
            return t1 > t ? t : t1;
        }

        if (i > j)
        {
            return compareFun(s, '0');
        }
        return compareFun(s, '1');
    }

    int compareFun(const string &str, char iniC)
    {
        char cmp = iniC;
        int res = 0;
        for (const char &c : str)
        {
            if (c != cmp)
            {
                ++res;
            }
            if (cmp == '0')
            {
                cmp = '1';
            }
            else
            {
                cmp = '0';
            }
        }
        return res/2;
    }
};
// @lc code=end
