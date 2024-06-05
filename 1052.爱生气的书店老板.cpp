/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int l = 0;
        int sum = 0;
        int cnt = 0;

        int maxCnt = -1;
        for (size_t r = 0; r < customers.size(); r++)
        {

            if (grumpy[r] == 0)
            {
                sum += customers[r];
            }
            else
            {
                cnt += customers[r];
            }
            if (r -l == minutes)
            {
                if (grumpy[l] == 1)
                {
                    cnt -= customers[l];
                }
                ++l;
            }
            
            
            maxCnt = maxCnt > cnt ? maxCnt : cnt;
        }

        return sum + maxCnt;
    }
};
// @lc code=end
