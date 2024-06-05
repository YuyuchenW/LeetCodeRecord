/*
 * @lc app=leetcode.cn id=1953 lang=cpp
 *
 * [1953] 你可以工作的最大周数
 */
#include<algorithm>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        if (milestones.size() == 1)
        {
            return 1ll;
        }
        
        sort(milestones.begin(), milestones.end());
        std::reverse(milestones.begin(), milestones.end());

        long long res = 0ll;
        int last = milestones[0];
        for (size_t i = 1; i < milestones.size(); i++)
        {
            if (last < milestones[i])
            {
                res += last + last;
                last = milestones[i] -last;
                milestones[i] = last;
            }
            else
            {
                res += milestones[i] + milestones[i];
                last -= milestones[i];
                milestones[i] = 0;
            }
        }
        if (milestones[milestones.size()-1] != 0 || last != 0)
        {
            ++res;
        }
        
        return res;
    }
};


// @lc code=end

