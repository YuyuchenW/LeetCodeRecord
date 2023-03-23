#include <string>
using namespace std;
class Solution
{
public:
    int mdfString(string &s)
    {
        int lo = 0, hi = 0;
        int cnt = 0;
        for (hi = 0; hi < s.size(); hi++)
        {
            if (s[hi] != '#')
            {
                s[lo] = s[hi];
                ++lo;
            }
            else
            {
                if (hi+1 -cnt -cnt>0)
                {
                    cnt++;
                }
                
                if (lo>0)
                {
                    --lo;
                    
                }
            }
        }
        return s.size()-cnt-cnt;
    }
    bool backspaceCompare(string s, string t)
    {
        if (s == t)
        {
            return true;
        }
        int i, k;
        i = mdfString(s);
        k = mdfString(t);
        if (i == k)
        {
            if (i == 0)
            {
                return true;
            }
            
            for (size_t j = 0; j < i; j++)
            {
                if (s[j] != t[j])
                {
                    return false;
                }
            }
        }else{return false;}
        return true;
    }
};