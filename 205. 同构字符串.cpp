#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;

        for (size_t i = 0; i < s.length(); i++)
        {
            if (!sMap.count(s[i]))
            {
                sMap.insert({s[i], t[i]});
            }
            if (!tMap.count(t[i]))
            {
                tMap.insert({t[i], s[i]});
            }
            if (tMap[t[i]] != s[i] || sMap[s[i]] != t[i])
            {
                return false;
            }
        }
        return true;
    }
};