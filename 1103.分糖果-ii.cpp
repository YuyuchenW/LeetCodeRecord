/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int index = 0;
        int need = 1;
        while (candies >= need)
        {
            candies -= need;
            res[index] += need;
            ++index;
            ++need;
            if (index >= num_people)
            {
                index = index % num_people;
            }
        }
        res[index] += candies;
        return res;
        
    }
};
// @lc code=end

