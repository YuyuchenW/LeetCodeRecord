/*
 * @lc app=leetcode.cn id=2192 lang=cpp
 *
 * [2192] 有向无环图中一个节点的所有祖先
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> res(n);
        for (auto &edge : edges)
        {
            if (res[edge[0]].size() != 0)
            {

                for (auto &i : res[edge[0]])
                {
                    res[edge[1]].push_back(i);
                }
            }
            res[edge[1]].push_back(edge[0]);
        }
        return res;
    }
};
// @lc code=end
