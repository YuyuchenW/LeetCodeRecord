/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */
#include <iostream>
#include <functional>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    const int diff = 'a' - 'A';
    vector<string> letterCasePermutation(string s)
    {
        vector<string> res;
        string path;
        std::function<void(int)> dfs = [&](int i)
        {
            if (i == s.size())
            {
                res.push_back(path);
                return;
            }
            char c = changeChar(s[i]);
            if (c == ' ')
            {
                path.push_back(s[i]);
                dfs(i + 1);
                path.pop_back();
            }
            else
            {
                
                path.push_back(s[i]);
                
                dfs(i + 1);
                path.pop_back();
                
                path.push_back(c);

                dfs(i + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return res;
    }

    char changeChar(char c)
    {
        if (c >= 'a' && c <= 'z')
        {
            c -= diff;
            return c;
        }
        if (c >= 'A' && c <= 'Z')
        {
            c += diff;
            return c;
        }
        return ' ';
    }
};
// @lc code=end
