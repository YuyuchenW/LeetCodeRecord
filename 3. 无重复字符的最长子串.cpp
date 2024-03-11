#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0;
        int map[128] = {0};
        int ans = 0;
        for (size_t i = 0; i <s.size(); ++i)
        {
            left = max(left, map[s[i]]);
            map[s[i]] = i+1;
            ans = max(ans, (int)i - left+1);
        }
        return ans;
    } 
};