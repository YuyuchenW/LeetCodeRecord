#include <string>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        string Key = "aeiouAEIOU";
        int left = 0;
        int right = s.size();

        while (left < right)
        {
            if (Key.find_first_of(s[left]) != string::npos && Key.find_first_of(s[right]) != string::npos)
            {
                char tep = s[left];
                s[left] = s[right];
                s[right] = tep;
                ++left;
                --right;
            }
            else if (Key.find_first_of(s[left]) == string::npos && Key.find_first_of(s[right]) != string::npos)
            {
                ++left;
            }
            else if (Key.find_first_of(s[left]) != string::npos && Key.find_first_of(s[right]) == string::npos)
            {
                --right;
            }
            else
            {
                ++left;
                --right;
            }
        }
        return s;
    }
};