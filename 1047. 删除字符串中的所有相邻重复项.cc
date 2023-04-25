#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> charSt;
        for (char c : s)
        {
            if (charSt.empty())
            {
                charSt.push(c);
            }
            else
            {
                if (charSt.top() == c)
                {
                    charSt.pop();
                }
                else
                {
                    charSt.push(c);
                }
            }
        }
        string result;
        while (!charSt.empty())
        {
            result.push_back(charSt.top());
            charSt.pop();
        }
        result.reserve();
        return result;
    }
};