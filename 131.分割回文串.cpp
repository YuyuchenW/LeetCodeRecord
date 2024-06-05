/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.size();
        dfs(0,n,path,ans,s);
        return ans;
    }

    void dfs(int i, const int &s, vector<string> path, vector<vector<string>> &ans, string &str)
    {
         
        if (i == s)
        {
            ans.push_back(path);
            return;
        }

        for (size_t k = 1; k <= s - i; k++)
        {
            string sub_str = str.substr(i, k);
            if (check(sub_str))
            {
                path.push_back(sub_str);
                dfs(i+k,s,path,ans,str);
                path.pop_back();
            }
        }
    }

    bool check(string str)
    {
        int l = 0;
        int r = str.size() - 1;
        while (l < r)
        {
            if (str[l] != str[r])
            {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};
// @lc code=end
