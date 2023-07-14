#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// 输入：s = "2[abc]3[cd]ef"
// 输出："abcabccdcdcdef"
class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> strs;
        stack<int> nums;
        int num = 0;
        string res = "";

        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                res.push_back(s[i]);
            }
            else if(s[i] == '[')
            {
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";  
            }
            else
            {
                int cnt = nums.top();
                nums.pop();
                for (size_t j = 0; j < cnt; ++j)
                {
                    strs.top() += res;
                }
                res = strs.top();
                strs.pop();
            }
        }
        return res;
        
    }
};