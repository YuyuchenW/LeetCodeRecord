/*
 * @lc app=leetcode.cn id=2928 lang=cpp
 *
 * [2928] 给小朋友们分糖果 I
 */

// @lc code=start
class Solution
{
public:
    int distributeCandies(int n, int limit)
    {
        int res = 0;
        dfs(0,n,limit,res);
        return res;
    }

    void dfs(int index, int n, int limit, int &res)
    {
        if (index == 2)
        {
            if (n <= limit)
            {
                ++res;
            }
            return;
        }
        if (n == 0)
        {
            return;
        }
        
        for (int i = 0; i <= n; i++)
        {
            if (i > limit)
            {
                break;
            }
            
            int tmp = n - i;
            dfs(index+1,tmp,limit,res);
        };
        return;
    }
};
// @lc code=end
