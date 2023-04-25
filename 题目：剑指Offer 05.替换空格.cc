#include<string>

using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        for(char c : s )
        {
            if (c == 32)
            {
                ++cnt;
            }
        }

        int left = s.size()-1;
        int right = s.size()+cnt*2-1;
        s.resize(s.size()+2*cnt);

        while (left>=0)
        {
            if (s[left] != 32)
            {
                s[right] = s[left];
            }
            else{
                s[right--] = '0';
                s[right--] = '2';
                s[right] = '%';
            }
            --left;
            --right;
        }
        return s;
    }
};