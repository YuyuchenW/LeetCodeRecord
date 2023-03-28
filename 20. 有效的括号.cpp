#include <string>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if(s.size()%2){return false;}
        unordered_map<char, char> mp = {
            {'}','{'},
            {')','('},
            {']','['}
        };
        stack<char> st;

        for(char c : s)
        {
            if (mp.count(c))
            {
                if (st.empty() || st.top()!=mp[c])
                {
                    return false;
                }
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        return st.empty();
    }
};