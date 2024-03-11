#include <string>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        char mp[128] = {0};
        for(char c: stones)
        {    
            ++mp[c];
        }

        int cnt = 0;
        for(char c : jewels)
        {
            cnt  += mp[c];
        }
        return cnt;
    }
};