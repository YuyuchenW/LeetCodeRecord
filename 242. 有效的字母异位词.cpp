#include<string>
using  namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size())
        {
            return false;
        }
        int mp[26] = {0};
        for(char c : s)
        {
            ++mp[c-'a'];
        }
        for(char c : t)
        {
            --mp[c-'a'];
        }

        for (size_t i = 0; i < 26; i++)
        {
            if (mp[i] !=0)
            {
                return false;
            }
        }
        return true;
    }
};