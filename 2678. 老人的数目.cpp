#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res =0;
        char compair = '6';
        for(string& s : details)
        {
            if (s[11] > compair)
            {
                ++res;
                continue;
            }
            if (s[11]==compair && s[12] != '0')
            {
                ++res;
            }
        }
        return res;
    }
};