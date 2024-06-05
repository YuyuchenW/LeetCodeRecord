#include <string>
using namespace std;
class Solution
{
public:
    string getSmallestString(string s, int k)
    {

        for (int i = 0; i < s.size(); ++i)
        {
            if (k == 0)
            {
                break;
            }
            if (s[i] > 'n')
            {
                if (s[i] + k > 'z')
                {
                    k -= (122 - s[i] + 1);
                    s[i] = 'a';
                }
                else
                {
                    s[i] = s[i] - k;
                    k = 0;
                }
            }
            else
            {
                if (s[i] - k < 'a')
                {
                    k -= s[i] - 'a';
                    s[i] = 'a';
                }
                else
                {
                    s[i] = s[i] - k;
                    k = 0;
                }
            }
        }
        return s;
    }
};