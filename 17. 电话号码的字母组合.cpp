#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string path;
    vector<string> result;
    void backTracking(const string &digits, const vector<vector<char>> &pin, int n)
    {
        if (path.size() == digits.size())
        {
            result.push_back(path);
        }
        if (n>= digits.size())
        {
            return;
        }
        int k = digits[n]-50;
        for (size_t i = 0; i < pin[k].size(); i++)
        {
            path.push_back(pin[k][i]);
            backTracking(digits,pin,n+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return result;
        }
        
        vector<vector<char>> pin = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

        backTracking(digits,pin,0);
        return result;
    }
};