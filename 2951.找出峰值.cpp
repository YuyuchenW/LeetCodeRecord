/*
 * @lc app=leetcode.cn id=2951 lang=cpp
 *
 * [2951] 找出峰值
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        if (mountain.size() < 3)
        {
            return {};
        }
        vector<int> res;
        int left = 0;
        int mid = 1;
        int right = 2;
        while (right < mountain.size())
        {
            if (mountain[mid] > mountain[left] && mountain[mid] > mountain[right])
            {
                res.push_back(mid);
            }
            ++left;
            ++mid;
            ++right;
        }
        
        return res;
    }
};
// @lc code=end

