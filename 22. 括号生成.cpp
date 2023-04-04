#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    void backTracking(vector<string>& ans, string& cur,int open,int close,int n)
    {
        if (cur.size() ==  2*n)
        {
            ans.push_back(cur);
        }
        if (open<n)
        {
            cur.push_back('(');
            backTracking(ans,cur,open+1,close,n);
            cur.pop_back();
        }
        if (close< open)
        {
            cur.push_back(')');
            backTracking(ans,cur,open,close+1,n);
            cur.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n)
    {
        string cur;
        vector<string> ans;
        backTracking(ans,cur,0,0,n);
        return ans;
    }
};