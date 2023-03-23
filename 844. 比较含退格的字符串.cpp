#include <string>
using namespace std;
class Solution {
public:
    string finalString(string s)
    {
        string fString;
        for(char i : s)
        {
            if (i!= '#')
            {
                fString.push_back(i);
            }
            else
            {
                if (!fString.empty())
                {
                    fString.pop_back();
                }
                
            }
        }
        return fString;
    }
    bool backspaceCompare(string s, string t) {
       return finalString(s) == finalString(t);
    }
};