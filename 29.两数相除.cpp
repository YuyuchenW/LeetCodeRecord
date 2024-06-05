/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include <stdint.h>
// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
        {
            return 0;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        if (divisor == -1)
        {
            if (dividend == INT32_MIN)
            {
                return INT32_MAX;
            }

            return -dividend;
        }
        if (divisor == 0)
        {
            return dividend > 0 ? INT32_MAX : INT32_MIN;
        }
        bool flag = true;
        if (dividend > 0 && divisor > 0)
        {
            flag = true;
        }
        else if (dividend < 0 && divisor < 0)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
        int res = 0;
        if (dividend == INT32_MIN )
        {
            
        }

        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor)
        {
            dividend -= divisor;
            ++res;
        }
        return flag ? res : -res;
    }
};
// @lc code=end
