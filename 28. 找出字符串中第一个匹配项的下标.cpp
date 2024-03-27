#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        
        for (size_t i = 0; i <= haystack.size() - needle.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                if (check(haystack, needle, i))
                {
                    return i;
                }
            }
        }
        return -1;
    }

    bool check(const string& haystack, const string& needle, const int& start)
    {
        for (size_t i = 0; i < needle.size(); i++)
        {
            if (haystack[start + i] != needle[i])
            {
                return false;
            }
        }
        return true;
    }
};