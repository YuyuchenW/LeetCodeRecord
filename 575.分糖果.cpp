/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> set;
        int typeNum = 0;
        for (const int &type : candyType)
        {
            if (set.count(type) != 0)
            {
                continue;
            }
            set.insert(type);
            ++typeNum;
        }

        int eat = candyType.size() /2;
        
        return typeNum < eat ? typeNum :eat;
    }
};
// @lc code=end
