#include <string>
using namespace std;

class Solution
{
public:
    void reverseSubStr(string &s, int left, int right)
    {
        while (left < right)
        {
            char tem = s[left];
            s[left] = s[right];
            s[right] = tem;
            ++left;
            --right;
        }
    }
    string reverseStr(string s, int k)
    {
        int left = 0;
        int right = 2 * k;
        while (s.size() >= right)
        {
            reverseSubStr(s, left, left + k - 1);
            left = right;
            right += 2 * k;
        }
        if (left == s.size())
        {
            return s;
        }
        int tem = s.size() - left;
        if (tem < k)
        {
            reverseSubStr(s, left, s.size() - 1);
        }
        else
        {
            reverseSubStr(s, left, left + k - 1);
        }
        return s;
    }
};