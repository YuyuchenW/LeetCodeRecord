/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits)
    {
        int k = digits.size();
        if (k == 0)
        {
            return {};
        }
        vector<string> res;
        string str = "";
        trackBack(k, str, res, digits, 0);
        return res;
    }

    void trackBack(const int k, string &str, vector<string>& res, const string &digits, int index)
    {
        if (index == k)
        {
            res.push_back(str);
        }
        
        for (char c : MAPPING[digits[index] - '0'])
        {
            str.push_back(c);
            trackBack(k, str, res, digits, index+1);
            str.pop_back();
        }
        return;
    }
};

// @lc code=end
