#include <string>
using namespace std;
class Solution
{
public:
    int toInt(const string &s, int ptr)
    {
        int result = 0;
        int size = 0;
        if (ptr>= s.size())
        {
            return 0;
        }
        
        while (s[ptr] == '0')
        {
            ++ptr;
        }
        
        for (size_t i = ptr; i < s.size(); i++)
        {
            if ('0' <= s[i] && s[i] <= '9')
            {
                result = (s[i] - '0')+ result * 10;
                ++size;
                if (size == 10)
                {
                    break;
                }
                
            }
            else
            {
                return result;
            }
        }
        return result;
    }
    int myAtoi(string s)
    {

        int result  = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == 43)
            {
                result = toInt(s,i+1);
                return result;
            }
            else if(s[i] == 45)
            {
                result = toInt(s,i+1);
                return 0-result;
            }
            else if('0' <= s[i] && s[i] <= '9')
            {
                result = toInt(s,i);
                return result;
            }
            else if(s[i] == ' '){}
            else{
                return result;
            }
        }
        return result; 
    }
};