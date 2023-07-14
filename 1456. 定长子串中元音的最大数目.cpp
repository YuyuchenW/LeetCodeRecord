#include <string>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int map[100] = {0};
        map['a'] = 1;
        map['e'] = 1;
        map['u'] = 1;
        map['i'] = 1;
        map['o'] = 1;

        int maxRes = 0;
        for (size_t i = 0; i < k; i++)
        {
            if (map[s[i]] == 1)
            {
                ++maxRes;
            }
        }


        int left = 0;
        int right = k - 1;
        int tem = maxRes;
        while (right < s.size() - 1)
        {
            ++right;
            if (map[s[right] == 1])
            {
                ++tem;
            }
            if (map[s[left]] ==1)
            {
                --tem;
            }
            ++left;
            maxRes = tem> maxRes ? tem : maxRes;
        }
        return maxRes;
    }
};