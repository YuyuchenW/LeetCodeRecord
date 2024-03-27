#include <string>

using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int low = 0;
        for (size_t fast = 0; fast < s.size(); fast++)
        {
            if (s[fast] == '1')
            {
                swap(s[fast], s[low]);
                ++low;
            }
        }
        if (s[s.size() - 1] == '0')
        {
            if (low != 0)
            {
                swap(s[s.size() - 1], s[--low]);
            }
        }
        return s;
    }
};