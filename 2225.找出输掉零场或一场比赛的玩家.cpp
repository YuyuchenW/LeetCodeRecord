/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 *
 * [2225] 找出输掉零场或一场比赛的玩家
 */
#include <vector>
#include <map>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> result(2,vector<int>(0));
        map<int, int> map;
        for(const vector<int> & item : matches)
        {
            if(map.find(item[0]) == map.end())
            {
                map[item[0]] = 0;
            }
            if(map.find(item[1]) == map.end())
            {
                map[item[1]] = 1;
            }
            else
            {
                map[item[1]]++;
            }
        }

        for(auto&  item : map)
        {
            if (item.second == 0)
            {
                result[0].push_back(item.first);
            }
            else if (item.second == 1)
            {
                result[1].push_back(item.first);
            }
        }
        return result;
    }
};
// @lc code=end
