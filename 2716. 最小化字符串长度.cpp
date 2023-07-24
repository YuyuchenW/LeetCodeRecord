#include<string>

using namespace std;

 
class Solution {
public:
    int minimizedStringLength(string s) {
        int mp[26] = {0};
        int cnt = 0;
        for(char c : s)
        {
            if (mp[c-'a'] == 0)
            {
                ++cnt;
                ++mp[c-'a'];
            }
        }
        
        return cnt;
    }
};