#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        int index_mp[2000] = {0};
        unordered_map<int, int> ump;
        int res = 1;
        int resi = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if(nums[i]%2 ==0)
            {
                resi = i;
                break;
            }
        }
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 2)
            {
                continue;
            }
            auto item = ump.find(nums[i]);
            if (item == ump.end())
            {
                ump.insert({nums[i], i});
                ++index_mp[i];
                if(res == 1)
                {
                    resi = nums[resi]>nums[i]?i:resi;
                }
            }
            else
            {
                ++index_mp[item->second];
               
               if (res == index_mp[item->second])
               {
                    resi = nums[resi]>item->first?item->second:resi;
               }
               else if (res< index_mp[item->second])
               {
                    res =  index_mp[item->second];
                    resi = item->second;
               }
               
               
            }
        }
        if (ump.empty())
        {
            return -1;
        }
        return nums[resi];
    }
};