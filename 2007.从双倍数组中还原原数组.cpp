/*
 * @lc app=leetcode.cn id=2007 lang=cpp
 *
 * [2007] 从双倍数组中还原原数组
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        
        vector<int> res;

        if (changed.size() % 2)
        {
            return res;
        }

        unordered_map<int, int> map;
        for (size_t i = 0; i < changed.size(); i++)
        {
            if (changed[i] % 2 != 0)
            {
                int tmp = changed[i] * 2;
                auto it = map.find(tmp);
                if (it != map.end())
                {
                    --map[tmp];
                    res.push_back(changed[i]);
                    continue;
                }
            }
            else{

                int tmp = changed[i]/2;
                auto it = map.find(tmp);
                if (it != map.end())
                {
                    --map[tmp];
                    res.push_back(tmp);
                    continue;
                }
                 tmp = changed[i] * 2;
                 it = map.find(tmp);
                if (it != map.end())
                {
                    --map[tmp];
                    res.push_back(changed[i]);
                    continue;
                }

            }
            ++map[changed[i]];
        }
        if (changed.size()/2 != res.size())
        {
            return {};
        }
        return res;
    }
};
// @lc code=end
