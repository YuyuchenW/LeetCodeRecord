#include <vector>
#include <unordered_map>
using namespace std;

// 哈希表
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> ump;
        for (size_t i = 0; i < nums.size(); i++)
        {
            ++ump[nums[i]];
        }
        for (auto i = ump.begin(); i != ump.end(); ++i)
        {
            if (i->second == 1)
            {
                return i->first;
            }
        }
        return 0;
    }
};

// 位运算

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {   
        int res = 0;
        for (size_t i = 0; i < 32; i++)
        {
            int andSum = 0;
            for(int num : nums)
            {
                andSum += (num >> i) & 1;
            }
            
            if (andSum%3)
            {
                res |=  (1 <<i);
            }
        }
        return res;        
    }
};