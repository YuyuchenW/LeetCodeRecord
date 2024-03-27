/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int left = 0, rigth = citations.size() - 1;

        while (left <= rigth)
        {
            int mid = (left + rigth) / 2;
            if (citations[mid] >=citations.size() - mid)
            {
                rigth = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return citations.size() - left;
    }
};
// @lc code=end
