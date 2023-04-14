#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp;
#define XX(c, val) \
    mp.insert(pair<char, int>(c, val));
        XX('I', 1);
        XX('V', 5);
        XX('X', 10);
        XX('L', 50);
        XX('C', 100);
        XX('D', 500);
        XX('M', 1000);
#undef XX
        int lastVal = 4000;
        int sum = 0;
        for (char c : s)
        {
            auto item = mp.find(c);
            if (item->second <= lastVal)
            {
                sum += item->second;
                lastVal = item->second;
            }
            else
            {
                sum = sum + item->second - lastVal - lastVal;
                lastVal = item->second;
            }
        }
    }
};