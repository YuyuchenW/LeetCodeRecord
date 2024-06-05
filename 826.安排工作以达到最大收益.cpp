/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */
#include<algorithm>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs(difficulty.size());
        int res = 0;
        for (size_t i = 0; i < difficulty.size(); i++)
        {
            jobs[i] = make_pair(profit[i], difficulty[i]);
        }

        sort(jobs.begin(), jobs.end());
        for (size_t i = 0; i < worker.size(); i++)
        {
            int pay = 0;
            for (size_t j = 0; j < jobs.size(); j++)
            {
                if (jobs[j].second <= worker[i])
                {
                    pay = jobs[j].first;
                }
            }
            res += pay;
        }
        return res;
    }
};
// @lc code=end

