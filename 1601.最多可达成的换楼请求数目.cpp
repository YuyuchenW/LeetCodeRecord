/*
 * @lc app=leetcode.cn id=1601 lang=cpp
 *
 * [1601] 最多可达成的换楼请求数目
 */
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> visited(requests.size(), 0);
        int ans = 0;
        function<void(int)> dfs = [&](int cnt)
        {

        };
    }


    vector<int> findNext(int& target, vector<vector<int>>& requests)
    {
        vector<int> ans;
        for (int i = 0; i < requests.size(); ++i)
        {
            if (requests[i][0] == target)
            {
                ans.push_back(i);
            }
        }
    }
};
// @lc code=end

