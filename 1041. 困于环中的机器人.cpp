#include <string>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int mp[2] = {0, 0};
        int index = 0;
        int cnt = 0;
        while (cnt < 4)
        {
            for (char s : instructions)
            {
                if (s == 'G')
                {
                    ++cnt;
                    if (index <= 1)
                    {
                        ++mp[index];
                    }
                    else
                    {
                        --mp[index - 2];
                    }
                }
                else if (s == 'R')
                {
                    ++index;
                    index = index % 4;
                }
                else
                {
                    index = (index + 3) % 4;
                }
            }
            if (cnt == 0)
            {
                break;
            }
            
        }
        if (mp[0] == 0 && mp[1] == 0)
            return true;
        return false;
    }
};