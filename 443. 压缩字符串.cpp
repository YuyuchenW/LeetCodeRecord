#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        unordered_map<char, int> ump;

        int res = 0;
        char temp = ' ';
        for (char c : chars)
        {
            if(temp != c)
            {
                ++res;
                ump[c] =1 ;
            }
            else{
                auto i = ump.find(c);
                if(i->second == 1)
                {
                    ++res;
                    ++ump[c];
                }
                
            }
            
        }
        return res;
    }
};