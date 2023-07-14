#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int slow = 0;
        int fast = 0;
        char tem = ' ';
        int cnt = 1;
        bool flg = false;
        while (fast< chars.size() && slow < chars.size())
        {
            if (chars[fast] != tem)
            {
                flg = false;
                if (cnt != 1)
                {
                    if(cnt >= 10)
                    {
                        ++slow;
                        ++slow;
                    }
                    else{
                        ++slow;
                    }
                    cnt = 1;
                }
                
                chars[slow] = chars[fast];
                tem = chars[fast];
                
                ++slow;
            }
            else{
                flg = true;
                ++cnt;
                if(cnt < 10)
                {chars[slow] = cnt + '0';}
                else{
                    chars[slow] = (cnt/10) + '0';
                    chars[slow+1] = (cnt%10) + '0';
                }
                
            }
            ++fast;
        }
        if(!flg){
            --slow;
        }
        if(cnt >=10)
        {
            chars.resize(slow +2);
        }
        else{
             chars.resize(slow +1);
        }
        
        return  chars.size();
    }
};