/*
 * @lc app=leetcode.cn id=2644 lang=cpp
 *
 * [2644] 找出可整除性得分最大的整数
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {
        unordered_map<int, int> map;
        int maxNum = -1;
        int maxCnt = -1;
        int res = -1;

        for (const int &n : nums)
        {
            if(map.find(n) == map.end())
            {
                map[n] = 1;
            }
            else{
                ++map[n];
            }
            maxNum = max(maxNum, n);
        }

        for (size_t i = 0; i < divisors.size(); i++)
        {
            int div = maxNum / divisors[i];
            int cnt = 0;
            while (div > 0)
            {
                auto it = map.find(divisors[i] * div);
                if (it != map.end())
                {
                    cnt += it->second;
                }
                if(nums.size() <= cnt)
                {break;}
                --div;
            }

            if (cnt == maxCnt)
            {
                res = res > divisors[i] ? divisors[i] : res;
            }

            if (cnt > maxCnt)
            {
                res = divisors[i];
                maxCnt = cnt;
            }
        }
        return res;
    }
};
// @lc code=end
