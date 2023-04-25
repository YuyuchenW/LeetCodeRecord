#include <string>
using namespace std;

class Solution
{
public:
    void reverseStr(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; ++i, --j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
    string reverseLeftWords(string s, int n)
    {
        int end = s.size()-1;
        reverseStr(s,0,end);
        reverseStr(s,0,end-n);
        reverseStr(s,end-n+1,end);
        return s;
    }
};