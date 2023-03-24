#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int sSize = s.size();
        int pSize = p.size();
        if (sSize < pSize)
        {
            return {};
        }
        vector<int> res;
        int mp[26] = {0};
        int pmp[26] = {0};
        for (size_t i = 0; i < pSize; i++)
        {
            ++pmp[p[i] - 'a'];
        }

        int left = 0;
        int right = 0;
        for (right = 0; right < sSize; ++right)
        {
            ++mp[s[right] - 'a'];
            if (right - left == pSize - 1)
            {
                bool isRes =true;
                for (size_t i = 0; i < pSize; i++)
                {
                    if (isRes)
                    {
                        isRes = (mp[p[i]-'a'] == pmp[p[i]-'a']);
                    }
                    else{break;}
                }
                if (isRes)
                {
                    res.push_back(left);
                }
                --mp[s[left]-'a'];
                ++left;
            }
        }
        return res;
    }
};