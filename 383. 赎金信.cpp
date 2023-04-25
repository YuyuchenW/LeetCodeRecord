#include <string>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int mp[26] = {0};
        for (char c : magazine)
        {
            ++mp[c - 'a'];
        }

        for (char c : ransomNote)
        {
            if (--mp[c - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};